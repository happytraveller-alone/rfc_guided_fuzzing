# GPT-4 RFC Analysis Tool

This Python script uses OpenAI's GPT-4 model to analyze C code files and compare them against RFC 8446 (TLS 1.3) specifications.

## Features

- Processes C files with names matching the pattern "id-*.c"
- Uses GPT-4 to analyze each file's content
- Generates JSON-formatted analysis results
- Saves analysis results in separate answer files
- Extracts JSON content from answer files and combines them into a single result file

## Prerequisites

- Python 3.x
- OpenAI Python library
- Valid OpenAI API key

## Setup

1. Install the required Python library:pip install openai
2. Replace the placeholder API key in the script with your actual OpenAI API key:openai.api_key = "YOUR_API_KEY_HERE"

3. Usage
Place your C files (named "id-*.c") in the same directory as the script.
Run the script: python gpt-4.py

    The script will process each C file, generate an analysis, and save the results.
4. Output
For each input file "id-X.c", an answer file "id-X-answer.txt" will be created.
A "result.json" file will be created, containing the combined JSON data from all answer files.

5. Function Descriptions
    - ask_GPT4: Calls the GPT-4 API with the given system intelligence and prompt.
    - extract_id: Extracts the ID number from the filename.
    - process_file: Processes a single C file, generates an analysis, and saves the result.
6. Note
This script uses the GPT-4 model, which may incur costs based on your OpenAI account's pricing plan. Please be aware of the potential charges when running this script.