"""
This file compiles the C code into a *.so library.
It modifies the original MakeFile after creating a copy.
"""
from shutil import copy2
from subprocess import run

def do(make_file):
    # sauvegarde ou restauration du makefile original
    saved_make_file = make_file.with_suffix(".mk.old")
    if saved_make_file.exists():
        make_file.unlink()
    else:
        copy2(make_file, saved_make_file)


    with open(saved_make_file, 'r') as f:
        content = f.readlines()
    content = ''.join(content)
    content = content.replace(
"""build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)""",          
"""build : prebuild $(PRODUCT)
\tgcc *.o $(INCLUDES) -shared -o liball.so


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)"""
    )
    with open(make_file, 'w') as f:
        f.write(content)

    run(f"make -C \"{make_file.parent.resolve()}\" -f \"{make_file.name}\" clean build",
                   shell=True)


