package com.pinetreeapps.apotd

import android.content.DialogInterface
import android.graphics.Color
import android.os.Bundle
import android.support.v7.app.AlertDialog
import android.support.v7.app.AppCompatActivity
import android.util.Log
import android.view.View
import android.view.View.*
import com.pinetreeapps.apotd.dal.Constants
import com.pinetreeapps.apotd.dal.PictureOfTheDayRepository
import com.pinetreeapps.apotd.model.PictureOfTheDay
import com.pinetreeapps.apotd.presenter.main.MainPresenter
import com.pinetreeapps.apotd.presenter.main.MainView
import com.squareup.picasso.Picasso
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.coroutines.experimental.android.UI

class MainActivity : AppCompatActivity(), MainView {

    private val TAG = MainActivity::class.java.simpleName

    private val repository = PictureOfTheDayRepository(Constants.APOTD_ENDPOINT, Constants.API_KEY)
    private val presenter = MainPresenter(UI, repository)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        hideStatusBar()

        setContentView(R.layout.activity_main)

        previousImageBtn.setOnClickListener {
            presenter.showPreviousAPOTD()
        }

        nextImageBtn.setOnClickListener {
            presenter.showNextAPOTD()
        }
    }

    override fun onStart() {
        super.onStart()
        presenter.attach(this)
    }

    override fun onStop() {
        presenter.detach()
        super.onStop()
    }

    override fun showError(errorMessage: String) {
        AlertDialog.Builder(this).setTitle("Error").setMessage(errorMessage).setCancelable(false)
                .setPositiveButton("OK", DialogInterface.OnClickListener { dialog, which ->
                    dialog.dismiss()
                }).show()
    }

    override fun showLoading(isLoading: Boolean) {
        Log.d(TAG, "is loading: $isLoading")
        if (isLoading) {
            busyOverlay.animate().alpha(1f).withStartAction {
                busyOverlay.visibility = View.VISIBLE
            }.start()
        } else {
            busyOverlay.animate().setStartDelay(300).alpha(0f).withEndAction {
                busyOverlay.visibility = GONE
            }.start()
        }
    }

    override fun showAPOTD(apotd: PictureOfTheDay) {
        Picasso.get().load(apotd.url).fit().into(apotdImage)
        titleTextView.text = apotd.title
    }

    override fun changeNextButtonState(isEnabled: Boolean) {
        nextImageBtn.visibility = if (isEnabled) VISIBLE else INVISIBLE
    }

    private fun hideStatusBar() {
        window.decorView.systemUiVisibility = View.SYSTEM_UI_FLAG_LAYOUT_STABLE or
                View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
        window.statusBarColor = Color.TRANSPARENT
    }
}
