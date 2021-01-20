# xblackreset
Xorg tool to reset absolute black to 0 while keeping rest of the ramp untouched. 

Primary use case is hackily improving black levels on CRT-displays while avoiding black crush. 

Example usage:
```bash
xcalib -alter -brightness 5 
xblackreset Output-0 
```

## License
GPL-2

Program is partly based on [xcalib](https://github.com/OpenICC/xcalib), credits to its authors.

