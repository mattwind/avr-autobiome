

# These 2 should match up, you should probably be compiling and writing to the same device!
# The first will be passed to the compiler/assembler to indicate the proper avr chip or device
#MCU_FLAG                = -mmcu=atmega128

# Where to find the AVR  stuff
AVR_DIR                         = $(prefix)

# This will be passed to LOADER/PROGRAMMER as is, whatever you want the loader to do, this is what you change
LOADER_FLAGS                    = -c avrispmkII -p m128 -P usb

# The headers we want to install when the library gets installed
include_HEADERS                 = biome/init.h


# The list of programs will are making.  These binaries can be written to the AVR device
bin_PROGRAMS                    = biome.bin

# Libraries we are creating, in this case we are creating only one library
# but we could list several
lib_LIBRARIES                   = libAVR_Biome.a

# This is our "main" program, the actual binary we will load and execute
biome_bin_SOURCES               = src/biome.cxx

# The source files that make up our library
libAVR_Biome_a_SOURCES          = src/init.S

LDADD                           = libAVR_Biome.a -L $(AVR_DIR)/lib


# This is where we take off into AVR land.  Our program.bin files are what would normally be an
# executable.  Our regular executable needs to be stripped by objcopy and "flashed" to AVR device.
%.hex:%.bin
	$(OBJCOPY)  -j .data -j .text -O ihex $< $@

# To do the actual flashing we are going to use whatever the variables $LOAD and $LOAD_FLAGS
# contain.
%.write:%.hex
	$(LOAD) $(LOAD_FLAGS) -e -U flash:w:$^

