# Notes for route planning

## main function developments

1. std::optional
The class template std::optional manages an **optional contained** value, i.e. a value that may or may not be present.

A common use case for optional is the return value of a function that may fail. As opposed to other approaches, such as std::pair<T,bool>, optional handles expensive-to-construct objects well and is more readable, as the intent is expressed explicitly.