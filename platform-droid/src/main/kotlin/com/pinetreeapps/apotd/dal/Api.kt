package com.pinetreeapps.apotd.dal

import com.pinetreeapps.apotd.model.PictureOfTheDay
import kotlinx.coroutines.experimental.Deferred
import retrofit2.http.GET
import retrofit2.http.Query

interface Api {

    @GET("apod")
    fun getAPOTD(@Query("api_key") apiKey: String, @Query("date")
    date: String): Deferred<PictureOfTheDay>

}
