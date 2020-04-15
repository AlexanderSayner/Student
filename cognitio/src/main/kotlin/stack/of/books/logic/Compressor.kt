package stack.of.books.logic

class Compressor(private val alphabet: List<String>) {
    private var _codes: LinkedHashMap<String, String>? = null
    private val codes: LinkedHashMap<String, String>
        get() {
            if (_codes == null) {
                _codes = LinkedHashMap()

                var code = "0"
                var stepCounter = 0
                _codes!![alphabet[stepCounter]] = code
                while (++stepCounter < alphabet.size - 1) {
                    code = "1$code"
                    _codes!![alphabet[stepCounter]] = code
                }
                _codes!![alphabet[stepCounter]] = code.replace("0", "1", true)
            }
            return _codes ?: throw AssertionError("Set to null by another thread")
        }

    init {
        codes.forEach { (letter, code) -> println("$letter : $code") }
        _codes?.forEach { (letter, code) -> println("$letter : $code") }
    }
}