.PHONY: all clean prepare build

SUBDIRS = ../cbui ../cbutil ../cbdiags ../stup ../dsktp

all: prepare build

prepare:
	@chmod +x build.sh
	@./build.sh

build:
	@for dir in $(SUBDIRS); do \
		echo ">>> Building $$dir"; \
		$(MAKE) -C $$dir || exit 1; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo ">>> Cleaning $$dir"; \
		$(MAKE) -C $$dir clean; \
	done
