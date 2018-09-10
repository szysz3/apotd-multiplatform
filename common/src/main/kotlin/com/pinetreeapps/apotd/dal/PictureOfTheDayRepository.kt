package com.pinetreeapps.apotd.dal

import com.pinetreeapps.apotd.model.PictureOfTheDay

expect class PictureOfTheDayRepository {
    suspend fun getAPOTD(date: String): PictureOfTheDay
}