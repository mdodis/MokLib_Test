# Sample images
This is a collection of 4x4 "structured art" image files for testing importers

## Conformance
For all images, the resulting array of pixels *must* have the following values:

```c
{
    255,   0,   0, 255,    0,   0, 255, 255,
      0, 255,   0, 255,  255, 255, 255, 255
}
```

or, in words:

```c
{
    0xff0000ff, 0x0000ffff,
    0x00ff00ff, 0xffffffff
}
```