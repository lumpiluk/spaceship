import sys, getopt
from os import listdir
from os.path import isfile, join, split

import re # regular expressions

import csv


SOA_VALS = [-.1, -.05, 0, .05, .1]
LUM_VALS = [round(l, 3) for l in [0.345098, 0.470588, 0.596078, 0.878431]]
print(LUM_VALS)

class FrequencyTable:

	def __init__(self):
		self.table = {}
		for l in LUM_VALS:
			self.table[l] = {}
			for s in SOA_VALS:
				self.table[l][s] = {'repetitions': 0, 'probe_first': 0}
	
	#def set_value()


def show_help():
	print("\nUsage: make_toj.py [-i file] [-d directory]")
	print("Takes a subject-000.csv file or a folder containing several such files from the game/experiment Spaceship and creates the TOJ files.")
	print("Output files will be named toj_<original file name>.")


def save_toj(filename, frequency_table):
	'''
	Saves a dictionary of dictionaries frequencies as CSV to the given file
	name.
	frequencies: an instance of FrequencyTable
	'''

	with open(filename, 'w') as csv_out:
		csv_writer = csv.writer(csv_out, delimiter=';',
				quotechar='"', lineterminator='\n')
		
		for lum in LUM_VALS:
			# header
			csv_writer.writerow(['TargetLuminance=' + str(lum)])
			csv_writer.writerow(SOA_VALS)
			
			# repetitions row
			row = []
			for v in SOA_VALS:
				row.append(frequency_table.table[lum][v]['repetitions'])
			csv_writer.writerow(row)
			
			# "probe first" count row
			row = []
			for v in SOA_VALS:
				row.append(frequency_table.table[lum][v]['probe_first'])
			csv_writer.writerow(row)
			csv_writer.writerow([])


def create_toj(filename, frequencies_global):
	# determine output filename
	head, tail = split(filename)
	output_filename = join(head, 'toj_' + tail)
	
	# init frequencies table (representation of the CSV to write)
	frequencies = FrequencyTable()
	
	# parse input csv
	with open(filename, 'r') as csv_file:
		csv_reader = csv.DictReader(csv_file, delimiter=';', quotechar='"')
		
		for row in csv_reader:
			if row['Tutorial'] == 'true':
				continue
			
			target_lum = round(float(row['TargetLuminance']), 3)
			
			target_soa = float(row['SOA1'])
			if (row['StimTargetID'] == row['StimPair2Target']):
				target_soa = float(row['SOA2'])
			
			frequencies.table[target_lum][target_soa]['repetitions'] += 1
			frequencies_global.table[target_lum][target_soa]['repetitions'] += 1
			if row['TargetSelected'] == 'true':
				frequencies.table[target_lum][target_soa]['probe_first'] += 1
				frequencies_global.table[target_lum][target_soa]['probe_first'] += 1
	
	# save toj_subject-000.csv file
	save_toj(output_filename, frequencies)


try:
	opts, args = getopt.getopt(sys.argv[1:], "hi:d:")
except getopt.GetoptError:
	show_help()
	sys.exit(2)

if len(opts) == 0:
	show_help()
	sys.exit()

input_filenames = []
input_dir = None
	
for opt, arg in opts:
	if opt == '-h':
		show_help()
		sys.exit()
	if opt == '-i':
		input_filenames.append(arg)
	elif opt == '-d':
		input_dir = arg;

# if a directory was specified, add all relevant files to input_filenames
if not input_dir is None:
	p_csv = re.compile(r"subject-[\d]+.csv")
	p_toj = re.compile(r"toj_subject")
	p_lock = re.compile(r"lock")
	for file in listdir(input_dir):
		if (isfile(join(input_dir, file)) and p_csv.search(file) and not
				p_lock.search(file) and not p_toj.search(file)):
			input_filenames.append(join(input_dir, file))

print("Creating TOJ files using the following subject CSVs:")
print(str(input_filenames))
print()

frequencies_global = FrequencyTable()
for filename in input_filenames:
	print("Creating toj file for " + filename)
	create_toj(filename, frequencies_global)

# save global results
if (len(input_filenames) > 1):
	head, tail = split(input_filenames[0])
	filename = join(head, 'toj_all.csv')
	print("Creating global toj file: " + filename)
	save_toj(filename, frequencies_global)