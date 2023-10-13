################################################################################
#
#  update_versions utility
#  (for MapWiz)
#
#  ---
#
#  This utility updates version numbers globally across sourcefile headers.
#
#  !! WARNING !!
#  For safety, always run on a clean working tree, then diff and make sure
#  everything is in order before committing to branch!
#
#  ---
#
#  !! DEFINITELY !! do NOT run if you have no idea what you're doing.
#
################################################################################

import fileinput
import sys
import os
import glob
import re

def fetchSourcesList():
	sources = []
	for f in ['../src/*.cpp', '../src/*.h', '../src/res/*.h', '../src/gui/*.cpp', '../src/gui/*.h']:
		sources.extend(os.path.normpath(p) for p in glob.glob(f))
	return sources

def updateSourcesVersions(sources, version):
	for sourcefile in sources:
		for i, line in enumerate(fileinput.input(sourcefile, inplace=True)):
			if i == 3:
				nextline = '//  | | | | . | . | | | | |- _|  version ' + version
				print(nextline)
			else:
				print(line, end='')
		sys.stdout.write('Updated ' + sourcefile + '\n')

if __name__ == '__main__':
	if len(sys.argv) < 2:
		sys.stdout.write('Usage: {util} [next version]\n'.format(util = sys.argv[0]))
		sys.exit(0)
	version = sys.argv[1]
	version_regex = r'^\d+\.\d+\.\d+(\s\w+)?$'
	if not re.match(version_regex, version):
		sys.stdout.write('Not a valid version: ' + version)
		sys.exit(0)
	updateSourcesVersions(fetchSourcesList(), version)
	