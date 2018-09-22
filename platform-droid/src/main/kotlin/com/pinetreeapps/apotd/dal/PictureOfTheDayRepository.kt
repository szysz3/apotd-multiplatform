package com.pinetreeapps.apotd.dal

import com.jakewharton.retrofit2.adapter.kotlin.coroutines.experimental.CoroutineCallAdapterFactory
import com.pinetreeapps.apotd.utils.Date
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory

actual class PictureOfTheDayRepository(private val baseUrl: String, private val apiKey: String) {
    private val api: Api by lazy {
        Retrofit.Builder().addConverterFactory(GsonConverterFactory.create())
                .addCallAdapterFactory(CoroutineCallAdapterFactory()).baseUrl(baseUrl).build()
                .create(Api::class.java)
    }

    actual suspend fun getAPOTD(date: Date) =
            api.getAPOTD(apiKey, date.toDateFormatString()).await()

}

