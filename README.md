# zmk-config-corneft-oled

Konfiguracja ZMK dla **Corne FT** z **OLED i logo FalbaTech**.

## Hardware

- Shield: `corne` (oficjalny, w upstream ZMK)
- Kontrolery: 2× nice!nano v2
- Wyświetlacz: **OLED SSD1306 128×32** na obu połówkach
- Per-key RGB: 27 LED WS2812 na każdej połówce (6 underglow + 21 per-key)
- 42 klawisze (3 rzędy × 6 kolumn + 3 thumb na stronę)

## Wyświetlacz

| Połówka | Co pokazuje |
|---------|-------------|
| Lewa (USB, central) | Battery %, output (BT/USB), aktywna warstwa |
| Prawa (peripheral) | **Logo FalbaTech** na pełnym ekranie |

Logo jest custom widgetem skompilowanym z bitmapy 128×32. Patrz `src/falbatech_logo.c`
i `src/status_screen.c`.

## Wymiana logo

Jeśli chcesz inny obraz na peripheralu:

1. Przygotuj PNG monochromatyczny dokładnie 128×32 piksele
2. Skonwertuj na C array LVGL (np. https://lvgl.io/tools/imageconverter, format LV_IMG_CF_INDEXED_1BIT, czy z Pythona PIL)
3. Podmień zawartość `src/falbatech_logo.c` (zachowując nazwę zmiennej `falbatech_logo`)
4. Push → build

## Warstwy

| # | Nazwa | Funkcja |
|---|-------|---------|
| 0 | DEF | QWERTY base |
| 1 | NAV | Strzałki, numpad, BT |
| 2 | SYM | Symbole, brackets |
| 3 | ADJ | F-keys, system, **RGB controls**, bootloader, studio_unlock |
| 4 | EXTRA | Mouse emulation |

## ZMK Studio

Aktywne. **Ujednolicona procedura w portfolio FalbaTech FT:**
trzymaj oba thumby aktywujące warstwy systemowe → wciśnij **skrajny lewy górny klawisz**.

## Build

GitHub Actions buduje 3 firmware automatycznie:
- `corne_left-nice_nano-zmk.uf2` (z OLED + Studio)
- `corne_right-nice_nano-zmk.uf2` (z OLED, pokazuje logo FalbaTech)
- `settings_reset-nice_nano-zmk.uf2`

## Flashowanie

1. Lewa USB → 2× reset → przeciągnij `corne_left-...uf2` na pendrive `NICENANO`
2. Prawa USB → 2× reset → `corne_right-...uf2`
3. Połącz TRRS → klawiatura **"Corne FT"** w BT
4. Logo FalbaTech wyświetli się na prawej połówce po połączeniu split

## Różnice względem `zmk-config-corneft` (z nice!view)

| | corneft (nice!view) | corneft-oled (OLED + logo) |
|---|---|---|
| Wyświetlacz | nice!view (Sharp Memory LCD) | OLED SSD1306 |
| Custom logo | nie | **tak (FalbaTech)** |
| Bateria | dłuższa (~50 µA na display) | krótsza (~20 mA na BT) |
| Cena BOM | wyższa (nice!view) | niższa (OLED) |
