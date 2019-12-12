#! /usr/bin/python3

import os

total = 0

for file in os.listdir("."):
  statinfo = os.stat(file)
  total = total + statinfo.st_size

print("total is", total)
