package com.pinetreeapps.apotd.dal

import kotlin.coroutines.experimental.*
import kotlin.coroutines.experimental.intrinsics.*
import com.pinetreeapps.apotd.model.PictureOfTheDay

actual open class PictureOfTheDayRepository {

    actual suspend fun getAPOTD(date: String): PictureOfTheDay {
        return suspendCoroutineOrReturn { continuation ->
            getAPOTD(date, continuation)
            COROUTINE_SUSPENDED
        }
    }

    open fun getAPOTD(date: String, callback: Continuation<PictureOfTheDay>) {
        throw NotImplementedError("Should be implemented on client side.")
    }

}