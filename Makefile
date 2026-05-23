BUILD_DIR = build
APP_NAME = "spectral"
APP_PATH = $(BUILD_DIR)/spectral_artefacts/$(APP_NAME).app

# default target
.PHONY: all
all: build

# build the project
.PHONY: build
build: configure
	@echo "Building project..."
	@cd $(BUILD_DIR) && make

# run the app
.PHONY: run
run: build
	@echo "Running $(APP_NAME)..."
	@open "$(APP_PATH)"

# clean build artifacts
.PHONY: clean
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)

# rebuild from scratch, then rerun
.PHONY: rerun
rebuild: clean run

# show help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  build      - Configure and build the project"
	@echo "  run        - Build and run the application"
	@echo "  clean      - Remove build directory"
	@echo "  rerun      - Clean and build from scratch, then run"
	@echo "  help       - Show this help message"

.PHONY: build run clean rerun help all