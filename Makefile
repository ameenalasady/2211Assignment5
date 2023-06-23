# Set the compiler to use
CC = gcc
# Set the compiler flags
CFLAGS = -Wall -Wextra -Werror
# Set the linker flags
LDFLAGS =
# List of object files to build
OBJFILES = university_db.o university_classes.o university_students.o
# Name of the final executable
TARGET = university_db

# Default target: build the final executable
all: $(TARGET)

# Rule to build the final executable from the object files
$(TARGET): $(OBJFILES)
	# Link the object files to create the final executable
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJFILES)

# Rule to build university_db.o from university_db.c and university_db.h
university_db.o: university_db.c university_db.h
	# Compile university_db.c to create university_db.o
	$(CC) $(CFLAGS) -c university_db.c

# Rule to build university_classes.o from university_classes.c and university_classes.h
university_classes.o: university_classes.c university_classes.h
	# Compile university_classes.c to create university_classes.o
	$(CC) $(CFLAGS) -c university_classes.c

# Rule to build university_students.o from university_students.c and university_students.h
university_students.o: university_students.c university_students.h
	# Compile university_students.c to create university_students.o
	$(CC) $(CFLAGS) -c university_students.c

# Rule to clean up intermediate files and the final executable
clean:
	# Remove all object files and the final executable
	rm -f $(OBJFILES) $(TARGET)

# Declare all and clean as phony targets (not filenames)
.PHONY: all clean
