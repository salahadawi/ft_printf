# ft_printf - Coding printf from scratch.

The aim of this project was to create our own printf function from scratch. This included string, integer and float conversions with flags such as ```#```, ```0```, ```-``` and ```+```.

Functions we were allowed to use:

* ```write```
* ```malloc```
* ```free```
* ```exit```
* functions included in ```<stdarg.h>```

Everything else was coded entirely from scratch.

# What has been implemented

* ```%c```, ```%s```, ```%p```  conversions.

* ```%d```, ```%i```, ```%o```, ```u```, ```%x```, and ```%X``` conversions with ```hh```, ```h```, ```ll``` and ```l``` flags.

* ```%f``` conversion with ```l``` and ```L``` flags.

* ```%%```, prints a literal % character

* ```#```, ```0```, ```-```, ```+``` and space flags.

* Minimum field-width.

* Precision

Format syntax:

```
%[parameter][flags][width][.precision][length]type
```

# Usage


