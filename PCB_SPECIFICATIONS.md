# PCB Design Specifications

## Board Dimensions
- Dimensions: 100mm x 100mm
- Thickness: 1.6mm

## Layer Stackup
- Layer 1: Top Signal
- Layer 2: GND
- Layer 3: Power
- Layer 4: Bottom Signal

## Component Placement
- U1: Microcontroller - Center of the board
- C1: Capacitor - Close to U1
- R1: Resistor - Next to C1

## GPIO Pin Assignments
- GPIO Pin 1: Sensor Input
- GPIO Pin 2: Pump Output
- GPIO Pin 3: LED Indicator

## Connector Details
- J1: Power Connector - 2.54mm pitch
- J2: Sensor Connector - 2.00mm pitch

## Bill of Materials (BOM)
| Item | Description | Quantity |
|------|-------------|----------|
| U1   | Microcontroller | 1 |
| C1   | Capacitor       | 2 |
| R1   | Resistor        | 2 |

## Thermal Management
- Use thermal vias for heat dissipation
- Component placement should consider airflow

## Routing Guidelines
- Keep traces as short as possible
- Avoid 90-degree corners for signal traces

## Manufacturing Recommendations
- Use 2 oz copper for power planes
- Minimum trace width: 10 mils

---