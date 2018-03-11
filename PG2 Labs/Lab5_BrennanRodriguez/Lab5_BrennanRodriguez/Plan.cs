/*
 * Have a class called NumbersList
 * the list object inside numbers list is a list<string[2]>, where the first spot is the type and the second is the number
 * the dictionary object is a dictionary of <string, int>
 * 
 * NumList will have 3 functions: LoadList, LoadDict, Search
 * LoadList
 *      Streamreader readline until endof stream
 *      Each line read will seperate into two strings, the first is the type and the second is the value
 *      We parse the second one as an int
 *      we then list.add a string[] of {type, vale}
 * LoadDict
 *      We will streamread readline until endofstream
 *      Each line read will be seperated into two string, and the 2nd one will be parsed as an int
 *      then we dict.add the combination of the two
 * SearchList
 *      for the list.count,
 *              
 */