#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void encryptImage(const string& imagePath, int key) {
    Mat image = imread(imagePath);
    Mat encryptedImage = (image * key) / (key + 1);

    imwrite("encrypted_image.png", encryptedImage);
    cout << "Image encrypted successfully. Encrypted image saved at: encrypted_image.png" << endl;
}

void decryptImage(const string& encryptedImagePath, int key) {
    Mat encryptedImage = imread(encryptedImagePath);
    Mat decryptedImage = (encryptedImage * (key + 1)) / key;

    imwrite("decrypted_image.png", decryptedImage);
    cout << "Image decrypted successfully. Decrypted image saved at: decrypted_image.png" << endl;
}

int main() {
    cout << "------------- Image Encryption Tool --------------" << endl;

    while (true) {
        cout << "Select an option:" << endl;
        cout << "1 - Encrypt image" << endl;
        cout << "2 - Decrypt image" << endl;
        cout << "Your choice: "
        int choice;
        cin >> choice;

        if (choice == '1') {
            int key;
            cout << "Enter encryption key: ";
            cin >> key;
            string imageLocation;
            cout << "Enter the location of the image: ";
            cin >> imageLocation;
            encryptImage(imageLocation, key);
        } else if (choice == '2') {
            int key;
            cout << "Enter decryption key: ";
            cin >> key;
            string encryptedImageLocation;
            cout << "Enter the location of the encrypted image: ";
            cin >> encryptedImageLocation;
            decryptImage(encryptedImageLocation, key);
        } else 
            cout << "Invalid choice. Please choose 'e' for encryption, 'd' for decryption, or 'q' to quit." << endl;
    }

    return 0;
}
