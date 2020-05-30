package sandbox.encoding.method.algorythm

class SeemsLikeAStaticOne {
    companion object {

        @JvmStatic
        private var codeKey: Map<String, String> = LinkedHashMap()

        @JvmStatic
        fun codeKey(pair: Pair<String, String>) {
            codeKey = codeKey.plus(pair)
        }

        fun getDictionary(): Map<String, String> {
            return codeKey
        }

        fun print() {
            codeKey.forEach { (t, u) -> println("for symbol $t code is $u") }
        }
    }
}
