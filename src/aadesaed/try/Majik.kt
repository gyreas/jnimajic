fun main() {
    System.loadLibrary("try");
    
    hello();
    val arr_ = arr();
    val cpair_arr = cpairFromArray(arr_);
    val asstr = cpair_arr.joinToString("==")
    println("array: ${arr_.joinToString("()")}")
    println("cpair_array: $asstr")
 }
