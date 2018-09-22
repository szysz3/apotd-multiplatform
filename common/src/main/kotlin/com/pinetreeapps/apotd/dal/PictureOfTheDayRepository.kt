package com.pinetreeapps.apotd.dal

import com.pinetreeapps.apotd.model.PictureOfTheDay
import com.pinetreeapps.apotd.utils.Date

expect class PictureOfTheDayRepository {
    suspend fun getAPOTD(date: Date): PictureOfTheDay
}