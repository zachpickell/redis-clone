# RESP (Redis Serialization Protocol)

## Types
| Prefix | Type          | Example            |
|--------|---------------|--------------------|
| `+`    | Simple string | `+PONG\r\n`        |
| `$`    | Bulk string   | `$4\r\nPING\r\n`   |
| `*`    | Array         | `*1\r\n$4\r\nPING\r\n` |

## Notes
- Every line ends with `\r\n`
-