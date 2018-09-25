import Foundation
import Alamofire
import SwiftyJSON
import AstronomyPictureOfTheDay

class ApotdParser {
    
    func parse(response: DataResponse<Any>) -> APOTDPictureOfTheDay? {
        if let result = response.result.value {
            let json = JSON(result)
            return APOTDPictureOfTheDay(
                date: json["date"].stringValue,
                explanation: json["explanation"].stringValue,
                media_type: json["media_type"].stringValue,
                title: json["title"].stringValue,
                url: json["url"].stringValue)
        } else {
            return nil
        }
    }
}
