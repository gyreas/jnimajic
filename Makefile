pwd := $(shell pwd)
srcdir := $(pwd)/src
build_dir := $(pwd)/build

pkgdir := $(srcdir)/aadesaed/try
kts := $(addprefix $(pkgdir)/, Majik.kt Try.kt)
jvmargs := -Djava.library.path=$(build_dir) -cp $(build_dir)

lib = libtry.so
libdir := $(pwd)/lib
cflags := -fPIC -shared -I./$(libdir)
libso = $(build_dir)/$(lib)

run: MajikKt.class
	kotlin  $(jvmargs) MajikKt
MajikKt.class: $(libso)
	@kotlinc -d $(build_dir) $(kts)
$(libso):
	mkdir -p $(build_dir)
	cc $(cflags) -o $(libso) $(srcdir)/try.c
clean:
	rm -rf $(build_dir)
