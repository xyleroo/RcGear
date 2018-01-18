# RcGear

This is a small Arduino Pro mini sketch to control the left
and right landing gear from one RC channel.
Each gear has a upper and lower limit switch and
a DC motor controlled by one half of a MX1508 H-bridge driver.

# Arudino Pins

| Pin | Port     | Description          |
|-----|----------|----------------------|
| Raw | -        | 5V                   |
| Gnd | -        | Gnd                  |
|     |          |                      |
| 2   | PD2 INT8 | receiver input       |
|     |          |                      |
| 3   | PD3      | left gear out limit  |
| 4   | PD4      | left gear in limit   |
| 5   | PD5      | right gear out limit |
| 6   | PD6      | right gear in limit  |
|     |          |                      |
| 8   | PB0      | left motor ina2      |
| 9   | PB1      | left motor ina1      |
|     |          |                      |
| 10  | PB2      | right motor inb2     |
| 11  | PB3      | right motor inb1     |
