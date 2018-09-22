package com.pinetreeapps.apotd.dal

import kotlin.coroutines.experimental.*
import kotlin.coroutines.experimental.intrinsics.*
import com.pinetreeapps.apotd.model.PictureOfTheDay
import com.pinetreeapps.apotd.utils.Date

actual open class PictureOfTheDayRepository {

    actual suspend fun getAPOTD(date: Date): PictureOfTheDay {
        return suspendCoroutineOrReturn { continuation ->
            getAPOTD(date, continuation)
            COROUTINE_SUSPENDED
        }
    }

    open fun getAPOTD(date: Date, callback: Continuation<PictureOfTheDay>) {
        throw NotImplementedError("Should be implemented on client side.")
    }

}