PYTHON = python3
VENV = venv

ACTIVATE = source $(VENV)/bin/activate

# Rodar projeto principal
run:
	$(VENV)/bin/python src/main.py

test:
	$(VENV)/bin/python -m unittest discover tests

install:
	$(VENV)/bin/pip install -r requirements.txt

docs:
	$(VENV)/bin/mkdocs serve

build-docs:
	$(VENV)/bin/mkdocs build

clean:
	rm -rf __pycache__ */__pycache__ site

.PHONY: run test install docs build-docs clean