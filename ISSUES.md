# Known issues
## I'm too lazy to fix at the moment

- std::stoull input never gets sanitized in generic message setSkin.
- SMART_EDGE_HORIZ image storage type is broken in inventories?
- Player data never gets deleted, ENET_EVENT_TYPE_DISCONNECT is currently unused.

# Other stuff that could be implemented/changed
- Proper inventory system.
- TileExtra data for main doors. I don't have time at the moment, though.
- Accounts and world saving.
- Parsing logon data to get usernames and etc.
- World management system.
- Handling for action|quit and quit_to_exit