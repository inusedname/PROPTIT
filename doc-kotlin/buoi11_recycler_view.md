# RecyclerView in Android

## What is RecyclerView ?
- Imagine that you have a list of item and they are from the same class.
- As usual, you have to create and inflate a View for every single item in the list. It is time-consuming, wasted of device resources. 
- RecyclerView - a part of Android Jetpack, was born to solve the problem. Just like its name, it reuses - recycles Views. The approach is: 
    + All item in the list are from the same class. 
    + They have the same layout, which is declared in an `item.xml` file.
    + We just need to inflate a finite number, enough layouts to fit the screen (around 7 - 10)
    + After an item scrolls off the screen, its view isn't destroyed. We just unbind that View from the item and reuse the View for the next item. We connect the data list with the RecyclerView.
- One more strength of RecyclerView is __dynamic list__: you are allowed to modify your data list in runtime and your data will be updated right on track.

## How to use ?
- Three main components to implement RecycleView are: 
    + `<RecyclerView>`: A `ViewGroup` represents Recycler View in your UI layout.
    + `RecyclerView.ViewHolder`: A reusable `View` which doesn't belong to any item. Items through `Adapter` will be binded to the ViewHolder, and the data will be visualized on the screen.
    + `RecyclerView.Adapter`: You control the RecyclerView by using this: creating `ViewHolders`, binding data from the list to the `ViewHolders`, making changes when the data list was modified..., setting `click listeners` on ViewHolders...
    + `LayoutManager`: You choose how your items will be displayed: in linear layour, or in grid layout...

### Step 1: Design item layout
```xml
<!-- layout/item_recycler_view.xml -->

<?xml version="1.0" encoding="utf-8"?>
<FrameLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:minHeight="64dp"
    android:orientation="horizontal">

        <TextView
            android:id="@+id/tv_item_name"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:paddingTop="10dp"
            android:text="@string/student_name1"
            android:textAppearance="?attr/textAppearanceSubtitle1" />

</FrameLayout>
```

### Step 2: Add RecyclerView to UI Layout
```xml
<!-- layout/fragment_demo_recycler -->

<?xml version="1.0" encoding="utf-8"?>
<FrameLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".DemoRecyclerFragment">

    <androidx.recyclerview.widget.RecyclerView
        android:id="@+id/rv_demo_recycler"
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        app:layoutManager="androidx.recyclerview.widget.LinearLayoutManager" />

</FrameLayout>
```
- We are using standard LayoutManager from Android, so if you want to use custom layout, [implement it programmatically](https://developer.android.com/guide/topics/ui/layout/recyclerview-custom)

### Step 3: Implement the Adapter
- The brief structure is:
```kt
class YourAdapter : RecyclerView.Adapter<YourViewHolder> {

    val list: List<Item>

    override fun onCreateViewHolder

    override fun onBindViewHolder

    override fun getItemCount

    inner class YourViewHolder : RecyclerView.ViewHolder

}
```
- Simple example from Google:
```kt
class FlowerAdapter(val flowerList: Array<String>) :
    RecyclerView.Adapter<FlowerAdapter.FlowerViewHolder>() {

    // Describes an item view and its place within the RecyclerView
    class FlowerViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        private val flowerTextView: TextView = itemView.findViewById(R.id.flower_text)

        fun bind(word: String) {
            flowerTextView.text = word
        }
    }

    // Returns a new ViewHolder
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FlowerViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.flower_item, parent, false)

        return FlowerViewHolder(view)
    }

    // Returns size of data list
    override fun getItemCount(): Int {
        return flowerList.size
    }

    // Displays data at a certain position
    override fun onBindViewHolder(holder: FlowerViewHolder, position: Int) {
        holder.bind(flowerList[position])
    }
}
```
- My example, which provide `itemList` and `callBackOnItemClicked` in constructor, also apply `ViewBinding` to the `ViewHolder` instead of `View`:

```kt
class DemoRecyclerAdapter(
    private val dataList: List<Student>,
    private val onItemClicked: (Student) -> Unit
) : RecyclerView.Adapter<DemoRecyclerAdapter.DemoViewHolder>() {


    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): DemoViewHolder {
        return DemoViewHolder(
            ItemRecyclerViewBinding.inflate(LayoutInflater.from(parent.context), parent, false)
        )
    }

    override fun onBindViewHolder(holder: DemoViewHolder, position: Int) {
        holder.bind(dataList[position])
    }

    override fun getItemCount(): Int = dataList.size

    inner class DemoViewHolder(private val binding: ItemRecyclerViewBinding) :
        RecyclerView.ViewHolder(binding.root) {
        fun bind(student: Student) {
            binding.btItemGoToDetail.setOnClickListener {
                onItemClicked(student)
            }
            binding.tvItemName.text = student.name
            binding.tvItemSubName.text = student.dob
        }
    }
}
```

### Step 4: Setup your recyclerView with the adapter

```kt
override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Retrieves data from datasource
        val flowerList = Datasource(this).getFlowerList()

        val recyclerView: RecyclerView = findViewById(R.id.recycler_view)
        recyclerView.adapter = FlowerAdapter(flowerList)
    }
```
## Others
- When updating data list, you should trigger `notifyDataSetChanged()`
- It refresh the whole RecyclerView -> slow, waste resources.
- In bigger dataset, we should use `ListAdapter` + `DiffUtil` instead

## Shimmer (animation indicate that views are loading) 

- Two ways:
    + Quicker one: [ShimmerRecyclerView](https://github.com/sharish/ShimmerRecyclerView)
    + More custom: [Shimmer by Facebook](https://facebook.github.io/shimmer-android/)
-  Create a dummy ShimmerView lies in the same layout with the real RecyclerView. While the data is fetching, ShimmerView is running, and it will be set to View.GONE when things done.

## Load more/endless scrolling
- Brief:
    + Out of item listener: 
    ```kt
    recyclerView.addOnScrollListener(object : RecyclerView.OnScrollListener() {
        override fun onScrolled(recyclerView: RecyclerView, dx: Int, dy: Int) {
            super.onScrolled(recyclerView, dx, dy)
            if(!recyclerView.canScrollVertically(1)) {
                // LOAD MORE
            }
        }
    })
    ```
    + Add an Loading message/animation as the final item of RecyclerView.
    ```kt
    // Step 1: Add an extra null to the last position of dataset.
        // List = [1, 2, 3, 4, null]
    // Step 2: Override getItemViewType
    fun getItemViewType(position: Int): Int {
        return if (mItemList.get(position) == null) VIEW_TYPE_LOADING else VIEW_TYPE_ITEM
    }
    // Step 3: onCreateViewHolder, appropriately return base on getItemViewType()
    fun onCreateViewHolder(@NonNull parent: ViewGroup, viewType: Int): RecyclerView.ViewHolder? {
        return if (viewType == VIEW_TYPE_ITEM) {
            val view: View = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_row, parent, false)
            ItemViewHolder(view)
        } else {
            val view: View = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_loading, parent, false)
            LoadingViewHolder(view)
        }
    }
    ```
- Detail: https://www.digitalocean.com/community/tutorials/android-recyclerview-load-more-endless-scrolling