# 1. Extensions
SUFFIXES = .pgc .c

# 2. Executable name
bin_PROGRAMS = sample3

# 3. Maping original fonts
sample3_SOURCES = \
    src/sample3.pgc

sample3_CPPFLAGS = $(PG_INCLUDES)
sample3_LDFLAGS  = $(PG_LDFLAGS)
sample3_LDADD    = -lecpg

# 4. Integigent sulfix rules for the subdirectories
# O @mkdir -p $(@D) make sure that directory  build/src/ will be created before ecpg runs
.pgc.c:
	@mkdir -p $(@D)
	$(ECPG) $(PG_INCLUDES) -o $@ $<

# 5. Automatic cleaning
CLEANFILES = $(filter %.c, $(sample3_SOURCES:.pgc=.c))

