# zmk-config-corneft-oled

## PL

Konfiguracja ZMK dla **Corne FT z OLED i logo FalbaTech** na prawej połówce.

## Hardware

- Shield: `corne` (oficjalny shield upstream ZMK)
- Kontrolery: 2x nice!nano v2
- Wyświetlacz: OLED SSD1306 128x32 na obu połówkach
- RGB: per-key WS2812, 27 LED na każdej połówce
- 6 LED underglow + 21 per-key LED
- 42 klawisze, 3 rzędy x 6 kolumn + 3 thumb na stronę

## Wyświetlacz

| Połówka | Funkcja |
|---|---|
| Lewa, USB, central | Battery %, output BT/USB, aktywna warstwa |
| Prawa, peripheral | Logo FalbaTech na pełnym ekranie |

Logo jest custom widgetem skompilowanym z bitmapy 128x32.

Pliki:
- `src/falbatech_logo.c`
- `src/status_screen.c`

## Wymiana logo

Jeśli chcesz użyć własnego logo lub obrazu:

1. Przygotuj monochromatyczny PNG dokładnie 128x32 piksele.
2. Skonwertuj obraz do LVGL C array `LV_COLOR_FORMAT_I1`.
3. Podmień zawartość `src/falbatech_logo.c`.
4. Zachowaj nazwę zmiennej `falbatech_logo`.
5. Wykonaj push do repozytorium.
6. GitHub Actions automatycznie uruchomi build.

## Warstwy

| # | Nazwa | Funkcja |
|---|---|---|
| 0 | `DEF` | QWERTY base |
| 1 | `NAV` | Strzałki, nawigacja, numpad |
| 2 | `SYM` | Symbole, brackets |
| 3 | `ADJ` | F-keys, system, RGB controls, BT controls |
| 4 | `EXTRA` | Mouse emulation |

## ZMK Studio

ZMK Studio jest aktywne.

Procedura odblokowania jest taka sama we wszystkich klawiaturach FalbaTech FT:

> Trzymaj oba thumby aktywujące warstwy systemowe i wciśnij skrajny lewy górny klawisz.

Po odblokowaniu klawiatura jest edytowalna z poziomu przeglądarki:

https://zmk.studio

## Bluetooth - obsługa 5 urządzeń

Klawiatura obsługuje 5 niezależnych profili Bluetooth. Sterowanie odbywa się w warstwie systemowej `ADJ`.

| Klawisz | Funkcja |
|---|---|
| `Z` | Profil BT 0 |
| `X` | Profil BT 1 |
| `C` | Profil BT 2 |
| `V` | Profil BT 3 |
| `B` | Profil BT 4 |
| `N` | Wyczyść aktywny profil |
| `M` | Wyczyść wszystkie profile |
| `,` | Tryb USB |
| `.` | Tryb Bluetooth |

## RGB controls

Sterowanie RGB znajduje się w warstwie `ADJ`.

| Klawisz | Funkcja |
|---|---|
| `Q` | RGB toggle |
| `W` | Zmiana efektu |
| `E/R` | Hue +/- |
| `T/Y` | Brightness +/- |
| `U/I` | Saturation +/- |

## Build

GitHub Actions buduje 3 pliki firmware:

- `corne_left-nice_nano-zmk.uf2` - OLED + Studio
- `corne_right-nice_nano-zmk.uf2` - OLED + logo FalbaTech
- `settings_reset-nice_nano-zmk.uf2`

## Flashowanie

1. Podłącz lewą połówkę przez USB.
2. Naciśnij RESET dwa razy szybko.
3. Przeciągnij `corne_left-...uf2` na dysk `NICENANO`.
4. Podłącz prawą połówkę przez USB.
5. Naciśnij RESET dwa razy szybko.
6. Przeciągnij `corne_right-...uf2`.
7. Połącz obie połówki przewodem TRRS.
8. Sparuj klawiaturę jako "Corne FT" przez Bluetooth.
9. Logo FalbaTech pojawi się na prawej połówce po połączeniu split.

## Różnice względem wersji nice!view

| | corneft nice!view | corneft-oled |
|---|---|---|
| Wyświetlacz | nice!view Sharp Memory LCD | OLED SSD1306 |
| Custom logo | nie | tak |
| Zużycie baterii | niższe | wyższe |
| Cena BOM | wyższa | niższa |

## Wsparcie

FalbaTech  
https://falbatech.click

---

## EN

ZMK configuration for **Corne FT with OLED and FalbaTech logo** on the right half.

## Hardware

- Shield: `corne` (official upstream ZMK shield)
- Controllers: 2x nice!nano v2
- Display: OLED SSD1306 128x32 on both halves
- RGB: per-key WS2812, 27 LEDs on each half
- 6 underglow LEDs + 21 per-key LEDs
- 42 keys, 3 rows x 6 columns + 3 thumb keys per side

## Display

| Half | Function |
|---|---|
| Left, USB, central | Battery %, BT/USB output, active layer |
| Right, peripheral | Full screen FalbaTech logo |

The logo is a custom widget compiled from a 128x32 bitmap.

Files:
- `src/falbatech_logo.c`
- `src/status_screen.c`

## Replacing the logo

If you want to use your own logo or image:

1. Prepare a monochrome PNG exactly 128x32 pixels.
2. Convert the image into an LVGL C array `LV_COLOR_FORMAT_I1`.
3. Replace the contents of `src/falbatech_logo.c`.
4. Keep the variable name `falbatech_logo`.
5. Push changes to the repository.
6. GitHub Actions will automatically start the build.

## Layers

| # | Name | Function |
|---|---|---|
| 0 | `DEF` | QWERTY base |
| 1 | `NAV` | Arrows, navigation, numpad |
| 2 | `SYM` | Symbols, brackets |
| 3 | `ADJ` | F-keys, system, RGB controls, BT controls |
| 4 | `EXTRA` | Mouse emulation |

## ZMK Studio

ZMK Studio is enabled.

The unlock procedure is the same across all FalbaTech FT keyboards:

> Hold both thumb keys activating system layers and press the top left key.

After unlocking, the keyboard can be configured from your browser:

https://zmk.studio

## Bluetooth - 5 device support

The keyboard supports 5 independent Bluetooth profiles. Control is handled in the `ADJ` system layer.

| Key | Function |
|---|---|
| `Z` | BT Profile 0 |
| `X` | BT Profile 1 |
| `C` | BT Profile 2 |
| `V` | BT Profile 3 |
| `B` | BT Profile 4 |
| `N` | Clear active profile |
| `M` | Clear all profiles |
| `,` | USB mode |
| `.` | Bluetooth mode |

## RGB controls

RGB controls are located in the `ADJ` layer.

| Key | Function |
|---|---|
| `Q` | RGB toggle |
| `W` | Change effect |
| `E/R` | Hue +/- |
| `T/Y` | Brightness +/- |
| `U/I` | Saturation +/- |

## Build

GitHub Actions builds 3 firmware files:

- `corne_left-nice_nano-zmk.uf2` - OLED + Studio
- `corne_right-nice_nano-zmk.uf2` - OLED + FalbaTech logo
- `settings_reset-nice_nano-zmk.uf2`

## Flashing

1. Connect the left half via USB.
2. Press RESET twice quickly.
3. Drag `corne_left-...uf2` onto the `NICENANO` drive.
4. Connect the right half via USB.
5. Press RESET twice quickly.
6. Drag `corne_right-...uf2`.
7. Connect both halves using a TRRS cable.
8. Pair the keyboard as "Corne FT" over Bluetooth.
9. The FalbaTech logo will appear on the right half after split connection.

## Differences compared to the nice!view version

| | corneft nice!view | corneft-oled |
|---|---|---|
| Display | nice!view Sharp Memory LCD | OLED SSD1306 |
| Custom logo | no | yes |
| Battery usage | lower | higher |
| BOM cost | higher | lower |

## Support

FalbaTech  
https://falbatech.click
