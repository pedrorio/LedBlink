PORT=/dev/cu.usbserial-10

all:
	idf.py all

set-target:
	idf.py set-target esp32c3

menuconfig:
	idf.py menuconfig

setup_tools:
	pip install idf-component-manager --upgrade
	idf.py add-dependency espressif/led_strip

# app:
# 	idf.py app

# app-flash:
# 	idf.py app-flash -p $(PORT)

# bootloader:
# 	idf.py bootloader

# bootloader-flash:
# 	idf.py bootloader-flash -p $(PORT)

build-system-targets:
	idf.py build-system-targets

flash:
	idf.py flash -p $(PORT)
# 	[-b BAUD] default is 460800

monitor: # Delete build output files from the build directory.
	idf.py monitor -p $(PORT)

clean:
	idf.py clean

erase_flash:
	idf.py erase_flash # Erase entire flash chip.

#   confserver             Run JSON configuration server.

#   create-component       Create a new component.
#   create-project         Create a new project.

#   efuse_common_table     Generate C-source for IDF's eFuse fields.
#   efuse_custom_table     Generate C-source for user's eFuse fields.

#   encrypted-app-flash    Flash the encrypted app only.
#   encrypted-flash        Flash the encrypted project.

#   erase_otadata          Erase otadata partition.

#   fullclean              Delete the entire build directory contents.

#   gdb                    Run the GDB.
#   gdbgui                 GDB UI in default browser.
#   gdbtui                 GDB TUI mode.

#   openocd                Run openocd from current path

#   partition_table        Build only partition table.
#   partition_table-flash  Flash partition table only.

#   post_debug             Utility target to read the output of async debug action and stop them.

#   python-clean           Delete generated Python byte code from the IDF directory

#   read_otadata           Read otadata partition.

#   reconfigure            Re-run CMake.

#   show_efuse_table       Print eFuse table.

#   size                   Print basic size information about the app.
#   size-components        Print per-component size information.
#   size-files             Print per-source-file size information.