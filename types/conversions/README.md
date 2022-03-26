Conversion rules according to CERT C rule INT31-C:

	   1. Convertions which require validation:
	      	- from narrow type to thinner type
		- from unsigned type to signed type
	   	- from signed type to unsigned type

	   2. Convertions which not require validation:
	      	- from narrow type to wider type
