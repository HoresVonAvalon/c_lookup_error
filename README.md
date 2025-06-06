# c_lookup_error
## C Array Bounds Demonstration mit sicherer und unsicherer Variante


Dieses Repository enthält ein kleines C-Programm, das zwei Varianten einer Array-Indexabfrage zeigt, um in der Lehre zu demonstrieren, wie fehlende oder unzureichende Bounds-Checks in C dazu führen können, dass „geheime“ Daten ausgegeben werden oder ein Programm abstürzt.

## Inhalt des Repositories

- **`main.c`**  
  Enthält den C-Quellcode. Das Programm definiert ein gemeinsames Array `names[]` mit fünf Einträgen (`"test"`, `"paul"`, `"thomas"`, `"anton"`, `"secret"`). Über ein Top-Level-Menü wählt der Nutzer zwischen der **unsicheren Variante** (nur untere Schranke geprüft) und der **sicheren Variante** (obere und untere Schranke geprüft). So lässt sich live zeigen, wie ein einfacher Fehler ausreicht, um geheime Daten preiszugeben oder zu einem Absturz zu führen.

- **`Dockerfile`**  
  Baut das C-Programm mit GCC in einem Container und führt es als Einstiegspunkt aus. Damit kann jeder bequem ohne lokale Compiler-Installation testen.

- **`README.md`**  
  Diese Anleitung.

- **`LICENSE`**  
  MIT-Lizenz, unter der das Projekt steht.

## Voraussetzungen

- Docker (Version ≥ 20.10)  
- Grundkenntnisse in der Kommandozeile

## Schnellstart

1. Repository klonen (Terminal oder Git-GUI):

   ```bash
   git clone git@github.com:HoresVonAvalon/c_lookup_error.git
   cd c-array-lookup-error
   ```
2. Docker-Image bauen:
   ```bash
   docker build -t lookup_error .
   ```
3. Container Interaktiv starten:
   ```bash
   docker run --rm -it lookup_error
   ```
