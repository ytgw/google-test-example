.PHONY: all clean lib release test

all: clean lib release test run

clean:
	@-echo '##################################################'
	@-echo "# $@"
	@-echo '##################################################'
	make -C mylib clean
	make -C src clean
	make -C test clean

lib:
	@-echo '##################################################'
	@-echo "# $@"
	@-echo '##################################################'
	make -C mylib

release:
	@-echo '##################################################'
	@-echo "# $@"
	@-echo '##################################################'
	make -C src

test:
	@-echo '##################################################'
	@-echo "# $@"
	@-echo '##################################################'
	make -C test

run:
	@-echo '##################################################'
	@-echo "# $@"
	@-echo '##################################################'
	make -C src run