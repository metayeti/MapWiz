################################################################################
#
#  update_versions utility
#  (for MapWiz)
#
#  ---
#
#  This utility globally updates version numbers across:
#   - sourcefile headers
#   - the README.md file
#   - the MapWiz.rc file
#   - the const.h file
#
#  Usage: python update_versions.py [next version]
#                                        |
#              this parameter should be formatted in the form of x.x.x
#                (may be followed by a word, for example x.x.x dev)
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

def updateReadme(version):
	readmefile = '../README.md';
	for i, line in enumerate(fileinput.input(readmefile, inplace=True)):
		if i == 5:
			print('v' + version)
		else:
			print(line, end='')
	sys.stdout.write('Updated ' + readmefile + '\n')

def updateResourceFile(version):
	rcfile = '../res/MapWiz.rc'
	vsplit = version.split(' ')[0] # first split to remove the optional 2nd param
	vsplit2 = vsplit.split('.') # second split to get plain version numbers
	for i, line in enumerate(fileinput.input(rcfile, inplace=True)):
		if i == 64:
			nextline = ' PRODUCTVERSION {p1},{p2},{p3},0'.format(p1 = vsplit2[0], p2 = vsplit2[1], p3 = vsplit2[2])
			print(nextline)
		elif i == 85:
			nextline = '            VALUE "ProductVersion", "{p1}.{p2}.{p3}.0"'.format(p1 = vsplit2[0], p2 = vsplit2[1], p3 = vsplit2[2])
			print(nextline)
		else:
			print(line, end='')
	sys.stdout.write('Updated ' + rcfile + '\n')

def updateConstH(version):
	consthfile = '../src/const.h'
	for i, line in enumerate(fileinput.input(consthfile, inplace=True)):
		if i == 29:
			nextline = '\tconst char* const MAPWIZ_VERSION = "{version}";'.format(version = version)
			print(nextline)
		else:
			print(line, end='')
	sys.stdout.write('Updated ' + consthfile + '\n')

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
	updateReadme(version)
	updateResourceFile(version)
	updateConstH(version)
	