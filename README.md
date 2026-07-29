# ROT13

**ROT13 / Character Shift Utility**

Una semplice classe C++ che implementa un algoritmo di cifratura basato sullo spostamento dei caratteri. Oltre al classico **ROT13**, supporta anche uno **shift personalizzabile**, consentendo la codifica e la decodifica di stringhe e file di testo.

> **Nota:** questa implementazione non utilizza il classico algoritmo ROT13 sull'alfabeto (`A-Z`, `a-z`), ma effettua uno spostamento diretto del valore ASCII di ogni carattere.

---

## 📌 Descrizione

La classe `Rot13` permette di:

- codificare una stringa applicando uno shift di 13 caratteri;
- decodificare una stringa precedentemente codificata;
- utilizzare uno shift arbitrario definito dall'utente;
- convertire automaticamente il contenuto di un file di testo;
- salvare il risultato in un file di output.

Lo spostamento viene effettuato direttamente sul codice ASCII di ogni carattere.

---

## 🚀 Funzionalità

- ✅ **Costruttori**
  - Costruttore predefinito con shift pari a **13**.
  - Costruttore parametrizzato con valore di shift personalizzato.

- ✅ **Gestione dello shift**
  - Impostazione dello shift tramite `set_shift()`.
  - Recupero dello shift corrente tramite `get_shift()`.

- ✅ **Conversione delle stringhe**
  - Codifica tramite `rot13()`.
  - Decodifica tramite `rot13_reverse()`.

- ✅ **Shift personalizzato**
  - Codifica con qualsiasi valore mediante `rot_shift()`.
  - Decodifica con qualsiasi valore mediante `rot_shift_reverse()`.

- ✅ **Conversione dei file**
  - Lettura del contenuto di un file di testo.
  - Conversione riga per riga.
  - Scrittura automatica nel file `output.txt`.

---

## 📋 Requisiti

- **Linguaggio**
  - C++

- **Librerie standard**
  - `<string>`
  - `<fstream>`
  - `<iostream>`

---

## 💻 Utilizzo

### Creazione dell'oggetto

```cpp
Rot13 rot;
```

oppure con uno shift personalizzato:

```cpp
Rot13 rot(5);
```

---

### Codifica di una stringa

```cpp
string encrypted = rot.rot13("Hello World");
```

---

### Decodifica

```cpp
string decrypted = rot.rot13_reverse(encrypted);
```

---

### Utilizzo di uno shift personalizzato

```cpp
string encrypted = rot.rot_shift("Hello World", 5);
string decrypted = rot.rot_shift_reverse(encrypted, 5);
```

---

### Conversione di un file

Per codificare:

```cpp
rot.convert_file_to_rot13("input.txt");
```

Per decodificare:

```cpp
rot.convert_file_from_rot13("input.txt");
```

Il risultato verrà salvato automaticamente nel file:

```text
output.txt
```

---

## ⚙️ Come funziona

### 1. Inizializzazione

La classe memorizza il valore dello shift da utilizzare.

Per impostazione predefinita:

```cpp
shift = 13;
```

oppure può essere definito dall'utente.

---

### 2. Codifica

Ogni carattere della stringa viene convertito nel relativo valore ASCII e incrementato dello shift impostato.

```cpp
char c = char(int(character) + shift);
```

---

### 3. Decodifica

Per ottenere il testo originale viene eseguita l'operazione inversa:

```cpp
char c = char(int(character) - shift);
```

---

### 4. Conversione dei file

La classe:

1. apre il file di input;
2. legge il contenuto riga per riga;
3. converte ogni riga utilizzando lo shift scelto;
4. salva il risultato in `output.txt`.

---

## 📝 Metodi disponibili

| Metodo | Descrizione |
|---------|-------------|
| `Rot13()` | Costruttore con shift predefinito (13). |
| `Rot13(int shift)` | Costruttore con shift personalizzato. |
| `set_shift(int)` | Imposta il valore dello shift. |
| `get_shift()` | Restituisce lo shift corrente. |
| `rot13()` | Codifica una stringa con shift 13. |
| `rot13_reverse()` | Decodifica una stringa con shift 13. |
| `rot_shift()` | Codifica utilizzando uno shift arbitrario. |
| `rot_shift_reverse()` | Decodifica utilizzando uno shift arbitrario. |
| `convert_file_to_rot13()` | Converte un file di testo e lo salva in `output.txt`. |
| `convert_file_from_rot13()` | Decodifica un file di testo e lo salva in `output.txt`. |

---

## ⚠️ Limitazioni

- L'algoritmo **non implementa il ROT13 standard**, ma uno spostamento diretto dei valori ASCII.
- Non viene eseguito alcun controllo sull'overflow dei caratteri.
- Il file di output è sempre denominato **`output.txt`**.
- Il file viene aperto in modalità **append** (`ios::app`), quindi esecuzioni multiple aggiungono nuovi dati senza sovrascrivere quelli esistenti.
- La lettura del file utilizza il ciclo `while (!file.eof())`, una pratica generalmente sconsigliata in C++ moderno; è preferibile utilizzare `while (getline(file, line))`.

---

## 📄 Output

### Input

```text
Hello World
```

### Output (shift 13)

```text
Uryy|-\|yyq
```

*(L'output dipende direttamente dai codici ASCII dei caratteri e non corrisponde al ROT13 alfabetico tradizionale.)*
