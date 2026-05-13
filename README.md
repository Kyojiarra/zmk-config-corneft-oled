:::writing{variant=“standard” id=“61274”}

zmk-config-corneft-oled

PL

Konfiguracja ZMK dla Corne FT z OLED i logo FalbaTech na peripheralu.

Hardware
	•	Shield: corne (oficjalny w upstream ZMK)
	•	Kontrolery: 2× nice!nano v2
	•	Wyświetlacz: OLED SSD1306 128×32 na obu połówkach
	•	RGB: per-key WS2812, 27 LED na każdej połówce (6 underglow + 21 per-key)
	•	42 klawisze (3 rzędy × 6 kolumn + 3 thumb na stronę)

Wyświetlacz

Połówka	Co pokazuje
Lewa (USB, central)	Battery %, output (BT/USB), aktywna warstwa
Prawa (peripheral)	Logo FalbaTech na pełnym ekranie

Logo jest custom widgetem skompilowanym z bitmapy 128×32. Patrz src/falbatech_logo.c i src/status_screen.c.

Wymiana logo

Jeśli chcesz inny obraz na peripheralu:
	1.	Przygotuj PNG monochromatyczny dokładnie 128×32 piksele
	2.	Skonwertuj na C array LVGL (LV_COLOR_FORMAT_I1)
	3.	Podmień zawartość src/falbatech_logo.c (zachowując nazwę zmiennej falbatech_logo)
	4.	Push → build uruchomi się automatycznie

Warstwy

#	Nazwa	Funkcja
0	DEF	QWERTY base
1	NAV	Strzałki, nawigacja, numpad
2	SYM	Symbole, brackets
3	ADJ	F-keys, system, RGB controls, BT controls
4	EXTRA	Mouse emulation

ZMK Studio

Aktywne. Procedura odblokowania (jednakowa we wszystkich klawiaturach FalbaTech FT):

Trzymaj oba thumby aktywujące warstwy systemowe → wciśnij skrajny lewy górny klawisz.

Po odblokowaniu klawiatura jest edytowalna z:
zmk.studio￼

Bluetooth - obsługa 5 urządzeń

Klawiatura obsługuje 5 niezależnych profili Bluetooth. W warstwie systemowej (ADJ):

Klawisz	Funkcja
Z	Profil BT 0
X	Profil BT 1
C	Profil BT 2
V	Profil BT 3
B	Profil BT 4
N	Wyczyść aktywny profil
M	Wyczyść wszystkie profile
,	Tryb USB
.	Tryb Bluetooth

RGB controls

W warstwie ADJ (środkowy rząd):
	•	Q toggle
	•	W zmiana efektu
	•	E/R hue
	•	T/Y brightness
	•	U/I saturation

Build

GitHub Actions buduje 3 firmware:
	•	corne_left-nice_nano-zmk.uf2 (z OLED + Studio)
	•	corne_right-nice_nano-zmk.uf2 (z OLED, wyświetla logo FalbaTech)
	•	settings_reset-nice_nano-zmk.uf2

Flashowanie
	1.	Lewa USB - 2× reset - corne_left-...uf2
	2.	Prawa USB - 2× reset - corne_right-...uf2
	3.	Połącz obie połówki przewodem TRRS
	4.	Sparuj “Corne FT” przez Bluetooth
	5.	Logo FalbaTech wyświetli się na prawej połówce po połączeniu split

Różnice względem zmk-config-corneft (z nice!view)

	corneft (nice!view)	corneft-oled (OLED + logo)
Wyświetlacz	nice!view (Sharp Memory LCD)	OLED SSD1306
Custom logo	nie	tak (FalbaTech)
Bateria	dłuższa (~50 µA na display)	krótsza (~20 mA na BT)
Cena BOM	wyższa (nice!view)	niższa (OLED)

Wsparcie

FalbaTech - https://falbatech.click

⸻

EN

ZMK configuration for Corne FT with OLED and FalbaTech logo on the peripheral side.

Hardware
	•	Shield: corne (official upstream ZMK shield)
	•	Controllers: 2× nice!nano v2
	•	Display: OLED SSD1306 128×32 on both halves
	•	RGB: per-key WS2812, 27 LEDs on each half (6 underglow + 21 per-key)
	•	42 keys (3 rows × 6 columns + 3 thumb keys per side)

Display

Half	What it shows
Left (USB, central)	Battery %, output (BT/USB), active layer
Right (peripheral)	Full screen FalbaTech logo

The logo is a custom widget compiled from a 128×32 bitmap. See src/falbatech_logo.c and src/status_screen.c.

Replacing the logo

If you want a different image on the peripheral side:
	1.	Prepare a monochrome PNG exactly 128×32 pixels
	2.	Convert it into an LVGL C array (LV_COLOR_FORMAT_I1)
	3.	Replace the contents of src/falbatech_logo.c (keeping the variable name falbatech_logo)
	4.	Push → build starts automatically

Layers

#	Name	Function
0	DEF	QWERTY base
1	NAV	Arrows, navigation, numpad
2	SYM	Symbols, brackets
3	ADJ	F-keys, system, RGB controls, BT controls
4	EXTRA	Mouse emulation

ZMK Studio

Enabled. Unlock procedure (same across all FalbaTech FT keyboards):

Hold both thumb keys activating system layers → press the top left key.

After unlocking, the keyboard can be configured from:
zmk.studio￼

Bluetooth - 5 device support

The keyboard supports 5 independent Bluetooth profiles. In the system layer (ADJ):

Key	Function
Z	BT Profile 0
X	BT Profile 1
C	BT Profile 2
V	BT Profile 3
B	BT Profile 4
N	Clear active profile
M	Clear all profiles
,	USB mode
.	Bluetooth mode

RGB controls

In the ADJ layer (middle row):
	•	Q toggle
	•	W change effect
	•	E/R hue
	•	T/Y brightness
	•	U/I saturation

Build

GitHub Actions builds 3 firmware files:
	•	corne_left-nice_nano-zmk.uf2 (with OLED + Studio)
	•	corne_right-nice_nano-zmk.uf2 (with OLED, displays FalbaTech logo)
	•	settings_reset-nice_nano-zmk.uf2

Flashing
	1.	Left USB - press reset 2× - corne_left-...uf2
	2.	Right USB - press reset 2× - corne_right-...uf2
	3.	Connect both halves using the TRRS cable
	4.	Pair “Corne FT” over Bluetooth
	5.	FalbaTech logo appears on the right half after split connection

Differences compared to zmk-config-corneft (with nice!view)

	corneft (nice!view)	corneft-oled (OLED + logo)
Display	nice!view (Sharp Memory LCD)	OLED SSD1306
Custom logo	no	yes (FalbaTech)
Battery	longer (~50 µA on display)	shorter (~20 mA on BT)
BOM cost	higher (nice!view)	lower (OLED)

Support

FalbaTech - https://falbatech.click
:::
