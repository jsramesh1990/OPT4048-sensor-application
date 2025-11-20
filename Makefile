CC = gcc
CFLAGS = -Wall -O2

INPUT_GEN = input_generator
READER = opt4048_reader
APP = sensor_app

all: $(INPUT_GEN) $(READER) $(APP)

$(INPUT_GEN): input_generator.c
	$(CC) $(CFLAGS) $< -o $@

$(READER): opt4048_reader.c
	$(CC) $(CFLAGS) $< -o $@

$(APP): sensor_app.c
	$(CC) $(CFLAGS) $< -o $@

run: all
	@echo "Generating dummy input..."
	@./$(INPUT_GEN)
	@echo "Starting sensor_app..."
	@./$(APP)

clean:
	rm -f $(INPUT_GEN) $(READER) $(APP) *.txt

