# Non-blocking Serial Port Reader

This is non-blocking code for reading from a serial port. Features include:

- Reads are non-blocking, so Arduino code still runs while messages are read from the input buffer.
- Read timeouts prevent blocking in case a sender fails to send a complete message.
- Message parsing into a custom `Message` struct. Arguments for commands may be added to this struct.
- Commands may be added by extending the `enum class Command`
