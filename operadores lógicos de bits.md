# 📝 Lista de operadores lógicos de bits para `bitset`

## Tabla de operadores

| Operador | Qué hace | Ejemplo |
|----------|----------|---------|
| `&` (AND) | Devuelve 1 si ambos bits son 1, sino 0 | `1010 & 1100 → 1000` |
| `\|`(OR)  | Devuelve 1 si al menos uno de los bits es 1 | `1010 \| 1100 → 1110` |
| `^` (XOR) | Devuelve 1 si los bits son diferentes, 0 si son iguales | `1010 ^ 1100 → 0110` |
| `~` (NOT) | Invierte todos los bits (1→0, 0→1) | `~1010 → 0101` |
| `<<` (Shift left) | Mueve los bits a la izquierda n posiciones, rellenando con 0 | `1010 << 2 → 101000` |
| `>>` (Shift right) | Mueve los bits a la derecha n posiciones, descartando los desplazados | `1010 >> 2 → 10` |

---

## 🔹 Usos típicos con `bitset` o bits puros

- `bits |= (1 << pos)` → poner bit a 1  
- `bits &= ~(1 << pos)` → poner bit a 0  
- `bits ^= (1 << pos)` → invertir bit  
- `(bits & (1 << pos)) != 0` → testear bit  
- `bits <<= n` → desplazar a la izquierda  
- `bits >>= n` → desplazar a la derecha  
- `~bits` → invertir todos los bits
