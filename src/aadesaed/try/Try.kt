@file:JvmName("Try")

class CPair(val str: String, val len: Int) {
    override fun toString(): String {
	return Pair(this.str, this.len).toString()
    }
}

external fun hello();
external fun arr(): Array<String>;
external fun cpairFromArray(arrstr: Array<String>): Array<CPair>;
