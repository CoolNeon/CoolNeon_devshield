# Changelog

All notable changes to this project will be documented in this file.

## [Unreleased]

### Added
- `.github/copilot-instructions.md` — Copilot instruction file documenting project structure, API, naming conventions, and release process.

### Changed
- `release.yml`: version-already-released condition now skips the "Create release" step rather than failing the workflow
- Corrected the name of the Examples category found in the Arduino IDE.

## [1.2.2] - 2026-04-22

### Changed
- Reverted library name in `library.properties`
- Added `CHANGELOG.md`
- Added Contributing guidelines to `README.md`
- Set PR check mode to update

## [1.2.1] - 2026-04-21

### Added
- `README.md` replacing `README.txt`
- `SerialDebugger` example sketch for validating pin mappings
- GitHub Actions release workflow (`.github/workflows/release.yml`)

### Removed
- `README.txt`

## [1.2.0] - 2026-04-21

### Changed
- Renamed `DevShield.cpp` / `DevShield.h` to `CoolNeon_DevShield.cpp` / `CoolNeon_DevShield.h` to comply with Arduino library-registry lint requirements
- Updated `library.properties` metadata (name, URL, includes)
- Bumped version in `library.properties`
- Updated example sketches and `README.txt` to reference renamed header

## [1.1.0] - 2026-04-21

### Added
- GitHub Actions PR check workflow (`.github/workflows/pr-check.yml`)
- Additional pin definitions in `DevShield.h`

## [1.0.0] - 2026-04-21

### Added
- Initial release
- `DevShield.cpp` and `DevShield.h` library source
- `color_designer` and `PixelStepper` example sketches
- `library.properties`, `LICENSE.txt`, `README.txt`, `build.xml`
