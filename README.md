# :alien: apotd-multiplatform
[Astronomy Picture of the Day](https://apod.nasa.gov/apod/astropix.html) client for Android and iOS.

This project was created for educational purposes. I wanted to check new experimental feature ([Kotlin Multiplatform](https://kotlinlang.org/docs/reference/multiplatform.html) and [Kotlin\Native](https://kotlinlang.org/docs/reference/native-overview.html)) introduced in Kotlin 1.2. 
Those two allow you to write common code once and target different platforms: Android\iOS, desktop or even web.

## architecture

![arch](https://i.imgur.com/CIMKQJF.png)

##### `common`
This is a shared module. Contains only Kotlin classes with no platform specific dependencies. Classes with `expect` keyword go here.

##### `platform-android\ios`
Platform dependent implementations of classes declared in `common` module. Such implementations are marked with `actual` keyword.

##### `droid`
Regular Android app.

##### `ios`
Regular iOS app with dependency on binary `AstronomyPictureOfTheDay.framework`.

## setup

**1.** get your API key [here](https://api.nasa.gov/index.html#apply-for-an-api-key) and put it in [Constants.kt](https://github.com/szysz3/apotd-multiplatform/blob/6808cf70b2424c9a52da6cc699e5c65f74794290/common/src/main/kotlin/com/pinetreeapps/apotd/dal/Constants.kt#L6)

> val API_KEY = "[PUT YOUR API KEY HERE]"

**2.** build `AstronomyPictureOfTheDay.framework` and add as embedded binary to the iOS project:

```
gradle compileKonanAstronomyPictureOfTheDayIphone
```

**3.** run [`droid`](https://github.com/szysz3/apotd-multiplatform/tree/master/droid) with Android Studio

**4.** run [`ios`](https://github.com/szysz3/apotd-multiplatform/tree/master/ios/apotd) with XCode (remember to run `pod install` and open `.xcworkspace`)

## preview

|ios|droid|
|-----------|:-----------:|
|<img src="https://i.imgur.com/Cirgh4d.jpg" width="360">|<img src="https://i.imgur.com/aIKSZf8.jpg" width="360">|

## license

This project is licensed under the MIT license. See the [LICENSE](https://github.com/szysz3/apotd-multiplatform/blob/master/LICENSE) file for more info.
