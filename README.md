# MicroScan

This repo is a playground for figuring out how to interface with a SICK MicroScan3 laser scanner using its
[open source CPP driver](https://github.com/SICKAG/sick_safetyscanners_base).

## Prerequisities

- Linux
- Correctly setup SICK Safety Scanner
- Connected SICK Safety Scanner and a correctly setup ethernet network. Both the host and the sensor have to be in the same network
- installed libboost (`sudo apt install libboost-all-dev`)
- installed CPP driver library ([installation guide](https://github.com/SICKAG/sick_safetyscanners_base?tab=readme-ov-file#installation))