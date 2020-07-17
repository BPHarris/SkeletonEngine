#!/usr/bin/env python3
"""SkeletonEngine generate projects script.

Generate the SkeletonEngine project files for the given <target>.
On Windows, by default, this will generate a Visual Studio 2019 solution 'SkeletonEngine.sln' (<target> = 'vs2019').
On Linux and mac OS / OSX, by default, this will generate the appropriate Makefiles (<target> = 'gmake2').


Usage:
    generate_projects.py docs [viewdocs]
    generate_projects.py viewdocs
    generate_projects.py [<target>]

Options:
    --help, -h      show this

"""

from sys import argv
from platform import system

from os import system as call
from os.path import isdir, isfile, join

from vendor.include.docopt.docopt import docopt


def generate_projects(target : str) -> None:
    premake_relpath = join('.', 'vendor', 'bin', 'premake')

    if system() == 'Windows':
        premake_executable_relpath = join(premake_relpath, 'premake5.exe')
        target = target or 'vs2019'
    if system() == 'Linux':
        premake_executable_relpath = join(premake_relpath, 'premake5.linux')
        target = target or 'gmake2'
    if system() == 'Darwin':
        premake_executable_relpath = join(premake_relpath, 'premake5.osx')
        target = target or 'gmake2'
    
    call(f'{premake_executable_relpath} {target}')


def docs() -> None:
    call('cd Docs && make html')


def viewdocs() -> None:
    # docs_index_relpath = 'Docs/_build/html/index.html', adjusted to system
    docs_index_relpath = join('Docs', '_build', 'html', 'index.html')

    if not isfile(docs_index_relpath):
        print('error: docs index.html not found')
        quit()

    if system() == 'Windows':
        browser = 'explorer'
    if system() == 'Linux':
        browser = 'firefox-esr'
    if system() == 'Darwin':
        browser = 'open'

    call(f'{browser} {docs_index_relpath}')


if __name__ == '__main__':
    arguments = docopt(__doc__, argv[1:])

    if system() not in ('Windows', 'Linux', 'Darwin'):
        print('error: unsupported system', system())
        quit()

    if not any([arguments['docs'], arguments['viewdocs']]):
        generate_projects(arguments['<target>'])
    if arguments['docs']:
        docs()
    if arguments['viewdocs']:
        viewdocs()
