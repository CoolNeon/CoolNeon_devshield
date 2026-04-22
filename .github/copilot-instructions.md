# Copilot Instructions — CoolNeon DevShield

## Project Overview

This is an Arduino library (`CoolNeon DevShield`) for the CoolNeon Arduino Developer Shield. It is published to the Arduino Library Registry at:
`https://github.com/CoolNeon/CoolNeon_devshield`

The library provides pin definitions and a small helper class for the shield's inputs:
- 4 potentiometers (analog, A0–A3)
- 2 momentary push buttons (digital, pins 4–5)
- 2 two-position switches (digital, pins 6–7)
- Total Control Lighting (TCL) 4-pin output connector (Data pin 11, Clock pin 13)

## Source Files

| File | Purpose |
|---|---|
| `CoolNeon_DevShield.h` | Pin alias `#define`s and `DevShieldClass` declaration |
| `CoolNeon_DevShield.cpp` | `DevShieldClass` implementation |
| `library.properties` | Arduino library metadata (name, version, author, etc.) |
| `examples/color_designer/color_designer.ino` | Demo: read pots as RGB, print on button press |
| `examples/PixelStepper/PixelStepper.ino` | Demo: step RGB channel values with switches and buttons |
| `examples/SerialDebugger/SerialDebugger.ino` | Debug: validate physical pin-to-alias mappings |
| `CHANGELOG.md` | Version history |
| `README.md` | User-facing documentation |
| `.github/workflows/pr-check.yml` | PR checks: version bump validation + Arduino Lint |
| `.github/workflows/release.yml` | Auto-creates a GitHub release when a PR is merged to `main` |

## Pin Aliases (defined in `CoolNeon_DevShield.h`)

```cpp
DEVSHIELD_POT1       A0   // potentiometer 1, lower-left
DEVSHIELD_POT2       A1   // potentiometer 2, lower-right
DEVSHIELD_POT3       A2   // potentiometer 3, upper-right
DEVSHIELD_POT4       A3   // potentiometer 4, upper-left
DEVSHIELD_MOMENTARY1  4   // momentary button 1, lower
DEVSHIELD_MOMENTARY2  5   // momentary button 2, upper
DEVSHIELD_SWITCH1     6   // two-position switch 1, lower
DEVSHIELD_SWITCH2     7   // two-position switch 2, upper
DEVSHIELD_DATAPIN    11   // TCL data pin
DEVSHIELD_CLOCKPIN   13   // TCL clock pin
```

Do NOT use the legacy `TCL_` prefix (e.g. `TCL_MOMENTARY1`). All pin aliases use the `DEVSHIELD_` prefix.

## API

```cpp
DevShield.begin();              // Configure input pins with pull-up resistors; record initial switch state
DevShield.momentary1Pressed();  // Returns true while button 1 is held (accounts for manufacturing variation)
DevShield.momentary2Pressed();  // Returns true while button 2 is held
```

Potentiometers are read directly with `analogRead(DEVSHIELD_POTx)` (returns 0–1023).  
Switches are read directly with `digitalRead(DEVSHIELD_SWITCHx)`.

### Momentary button note

Due to manufacturing variation, ~50% of boards ship with the momentary buttons defaulting LOW (closed) instead of HIGH (open). `DevShield.begin()` snapshots the initial state; `momentary1Pressed()` / `momentary2Pressed()` compare against that snapshot instead of assuming a fixed resting level.

## Naming Conventions

- Class name: `DevShieldClass`; singleton instance: `DevShield`
- Pin macros: `DEVSHIELD_<INPUT>` (all caps)
- Header guard: `DevShield_h`
- The library folder and `#include` use `CoolNeon_DevShield` (e.g. `#include <CoolNeon_DevShield.h>`)

## Silkscreen Warning

The silkscreening on the aluminium cases for the DevShield is incorrect. Use `SerialDebugger.ino` to validate physical pin mappings.

## Versioning & Release Process

- Versions follow [Semantic Versioning](https://semver.org/): `MAJOR.MINOR.PATCH`
- The authoritative version lives in `library.properties` (`version=x.y.z`)
- **Every PR must bump the version** — the `pr-check` workflow will fail if the version tag already exists as a GitHub release
- When a PR is merged to `main`, the `release` workflow automatically creates a GitHub release tagged with the version from `library.properties`
- After release, the Arduino Library Registry scans for new versions hourly; check acceptance at:  
  `https://downloads.arduino.cc/libraries/logs/github.com/CoolNeon/CoolNeon_devshield/`

## Changelog

Keep `CHANGELOG.md` up to date with every PR. Follow the existing format:

```markdown
## [x.y.z] - YYYY-MM-DD

### Added
- ...

### Changed
- ...

### Removed
- ...
```

## Arduino Library Registry Compliance

The library must pass `arduino-lint` with `library-manager: update` and `compliance: specification`. Key requirements:
- Library folder/header name must match: `CoolNeon_DevShield`
- `library.properties` fields `name`, `version`, `author`, `sentence`, `url`, `includes` must be valid and present
- No spaces in the library folder name in the registry (uses `CoolNeon_devshield`)
