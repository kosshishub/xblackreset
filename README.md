# xblackreset
Tiny tool that resets gamma lut black level to 0 in Xorg.

Primary use case is improving CRT black levels while avoiding black crush. 

Example usage:
```bash
xcalib -alter -brightness 5 
xblackreset Output-0 
```

## License
GPLv2

