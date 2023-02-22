#!/usr/bin/python
import os, shutil
import argparse
import jinja2

seperator = "/"

def create_args_object():
    parser = argparse.ArgumentParser(
            prog = 'new_example',
            description = 'Example Template for New Programs')
    parser.add_argument('-f','--filename', help='Name of the project', required=True)
    parser.add_argument('-v','--verbose', help='Verbose log', action='store_true')
    return parser.parse_args()


def open_templates_create_files(args):

    template_folder = 'JinjaTemplates'
    filepath = os.getcwd() + seperator + template_folder

    if not os.path.exists(filepath):
        return

    templateLoader = jinja2.FileSystemLoader(searchpath=filepath)
    env = jinja2.Environment(loader=templateLoader, trim_blocks=True)

    # Get template for makefile
    template_makefile = env.get_template('Makefile.jinja2')
    template_gitignore = env.get_template('.gitignore.jinja2')

    print(template_gitignore.render(projectname=args.filename))

    if not os.path.exists(os.getcwd()+seperator+args.filename):
        os.mkdir(args.filename)

    new_folder = os.getcwd()+seperator+args.filename+seperator
    makefile_fd = open(new_folder + 'Makefile',mode='w+')
    gitignore_fd = open(new_folder + '.gitignore',mode='w+')
    makefile_fd.write(template_makefile.render(projectname=args.filename))
    gitignore_fd.write(template_gitignore.render(projectname=args.filename))

    os.chdir(args.filename+seperator)
    src = '..' + seperator + 'JinjaTemplates' + seperator + 'std_format.cpp'
    dest = args.filename + '.cpp'
    shutil.copy(src, '.')
    os.rename('std_format.cpp', dest)

    makefile_fd.close()
    gitignore_fd.close()

if __name__ == "__main__":
    args = create_args_object()
    open_templates_create_files(args)


