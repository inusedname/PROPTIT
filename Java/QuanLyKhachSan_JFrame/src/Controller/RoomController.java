package Controller;

import Controller.Exceptions.InvalidInput;
import Controller.Exceptions.NotFoundItem;
import Controller.Util.IOFile;
import Model.Phong;
import java.util.ArrayList;
import java.util.List;

public final class RoomController {

    private List<Phong> roomList;
    public String[] roomTypeList = {"VIP", "Chất lượng cao", "Thường"};

    public RoomController() {
        roomList = new ArrayList<>();
        loadRoom();
        if (!roomList.isEmpty()) {
            Phong.idPhongCount = roomList.get(roomList.size() - 1).getId() + 1;
        }
    }

    public void validateRoomName(String name) throws InvalidInput {
        if (name.length() == 0) {
            throw new InvalidInput("Tên phòng không được để trống");
        } else if (!name.matches("[A-Za-z][A-Za-z ]*")) {
            throw new InvalidInput("Tên phòng chỉ gồm các chữ cái");
        }
    }

    public String getRoomName(int index) {
        return roomList.get(index).getName();
    }

    public String getRoomType(int index) {
        return roomList.get(index).getLoaiphong();
    }

    public int getRoomID(int index) {
        return roomList.get(index).getId();
    }

    public void loadRoom() {
        roomList = IOFile.loadFromFile("PHONG.txt");
    }

    public void saveRoom() {
        IOFile.saveToFile("PHONG.txt", roomList);
    }

    public List<Phong> getRoomList() {
        return roomList;
    }

    public String addNewRoom(String name, String type) {
        try {
            validateRoomName(name);
            roomList.add(new Phong(name, type, -1));
            saveRoom();
            return "Thêm mới thành công";
        } catch (InvalidInput e) {
            return e.getMessage();
        }
    }

    public String removeRoom(int index) {
        roomList.remove(index);
        saveRoom();
        return "Xoá thành công";
    }

    public String editRoom(int index, String name, String type) {
        try {
            validateRoomName(name);
            roomList.set(index, new Phong(name, type, roomList.get(index).getId()));
            saveRoom();
            return "Sửa thành công";
        } catch (InvalidInput e) {
            return e.getMessage();
        }
    }
}
