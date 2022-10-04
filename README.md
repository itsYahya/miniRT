# MiniRT

	Mini ray tracer, a humble one but functional and ready to go.

## Algorithme

It's not that hard to understand, but i assure you its not as easy as it sounds.

First what is ray tracing, to talk about that we need to take a look at how the beuatiful human eye works.

Basicly how you get to read these lines.

You might already know that, but just let me tell you how it works. It's not gonna take long.

First of all, if you wanna see something, you need to provide a thing that called light to your eye, so it can give you an image in return, other than that, it's gonna be just setting there with no help at all.

So what is light, and how that thing works. Well light comes to us from a source of light in form of rays (it can be waves sometimes i don't know ``i ain't no scientist``), lets just call them rays.

Those rays as we just said come from the source of light to our eyes, but thoughout the long trip they've got intersect with some objects, and because each ray hits a different spot and some of them didn't intersect with any, that's obviouse that they gonna make it to the eye each one of them carrying a different color, `make sense ?`. 

	That's what makes you see what are you seeing right now.

See didn't take that long, i told you. Now lets jump right into it.

The idea of this algorithme is to simulate this act, we ganna shoot a ton of rays from the source of light and track them down to see what they hit. But wait we only need those rays how made it to the eye at the end, which is the camera in this case. 

So it's unnecessary to shoot in all direction, we gonna shoot only in the direction of the camera. 

We can still optimise this a little bit, cause let's say we have multiple source of light which is most likely to happen, it's gonna be hard to implement it in code, and i guess it's kinda stupid ``im gonna tell you why``.

What we gonna do instead is that we gonna shoot all the rays from the camera itself, like this we gonna make sure that we are not wasting any cycles of our poor ``CPU``, and its a lot easier for us to handle better than the approach we started with.

But wait again, how we gonna handle the shading, like to know whether the object we got intersected with is in the dark or not.

I got you, to solve this, the algorithme said that we gonne shoot another ray from that hit point to all the sources of light we have, if we got intersected we an object that means that our hit point is shaded other than that its lighted.

	I guess that's it about the algorithme, this is all we need to know to get started.

### Colors and lightning

	This is a part of the algorithme section.

We talked a bit about lightning, but what's lightning if we didn't bring ``coloring`` to the table.

So the image is just bunsh of pixels laying down next to each other, and each one of them have a color, which means every pixel is a color basically. But to define that color as we already said, we need to shoot a ray troughout every one of them, to know any color we gonna put at that particular pixel.

Let's say that we got intersected with an object, obviously the color of that pixel is the color of the object, but we need to take in consideration whether that object is in light or shaded.

We gonna go more in details about this in an up coming section below.

## Lib

Good **Data Structure** will make your life much easier, regarding to implementing any algorithme. but at this particular one is very mandatory.

You need to build a vector library, other than that the math at this project is almost impossible.

And a matrix library if you needed it ofcours its gonna be very helpful.

## Camera

Can you take a picture without a camera ? so as we, we cant rander an image without a camera.

Our camera is defined by 3 things :

* The origin fo the camera, which is ofcourse the point where the camera is at.

* The forword direction of the camera, which way the camera is looking.

* And last but not least the **FOV** stands for field of view.

We can't get a deeper understanding of how the camera would work, without knowing what is a **ray**.

### Ray

A ray is simply a line, and a line can be defined in different ways, two points or one point and a vector, which is the case. A ray will be defined with it's origin and it's direction, the origin is the point where it starts and which direction it's hitting.

So the ray will be represented with the following formula :

		origin + t * direction

* **origin** : is the point where that ray statrts from. 
* **direction** : the vector that represent the direction of the ray.
* **t** : is a parameter, which represent how many steps we should take to get to a point.

This formula called the parametrique equation, cause it containes that parameter **t**, with this equation we gonna find intersections.

The origins of our rays, gonna be the same as the camera's origin, but each one have it's own direction. The main problem here is how we gonna calculate the direction of each ray.

Well how we gonna solve this peoblem, first of all we are going to imaging that there's a plane facing the camera and one unit away from it. This last called the image plane, how it well help us solve this issue ? we'll see in a bit.

As you might already know if we wanted to travel in a line a vector will help us do so, what we mean by that, is that you multiplay that vector by some value and add it to a point that you certainly know it belongs to the line will gives us a point in that line. Why are we bringing this to the table, it's samply because we have a plane and if we needed to travel on it, it's mandatory to know first how to move on a line. What's a plane in the end, it's just a 2 dimensions space (left, right, up and down), i think now if we wanted to move on a plane we gonna need two vectors, one to handle up and down and the other one to handle the right and the left directions in that plane. In other words the first vector is in y-axis and the other in the x-axis.

A plan can be infinite, but we want our's to not be so. We need to define it's edges, in other words we need to define it's width and height, and by defining the up and the right vectors we gonna be able to move in that plane so easilly. 

#### The edges

Here where we gonna need to take a look at the informations of our camera. The **FOV** exactly, to calculate the height of that plane the feild of view will serves us to do it.

Before we continue let's set some keywords up :

* **HEIGHT** : is in pixel, which is the hight of our real image.
* **WIDTH** : in pixel too, which is the width of the real image.
* **height** : is the hight of our imaginary plane.
* **width** : the same is the with of the imaginary plane.
* **h** : represent **heght** / 2, half the height of the plane.
* **w** : represent **width** / 2, half the width of the plane.
* **ar** : which is the aspect ratio.

Well :
		
		We all know how to calculate the aspect ratio :
		
			ar = WDTH / HEIGHT = w / h

We gonna need this later on, keep it in mind.

Why we even mentioned that little **h** and **w**, actualy it's very helpful to use them, let's see why.

The problem here is how we gonna map our real **WIDTH** and **HEIGHT** to fitt in the imagenary plane we just talked about.
Like we said the plane is just tow axis, imagine that our axis are crossed in the middle `like they usually are`, so (0, 0) in the plane gonna match of course the (**WIDTH** / 2, **HEIGHT** / 2), the pixel at the center of the image, which is logic i guess.
The length of the y-axis gonna be the whole **hight** of the plane, but if (0, 0) is at the center that means that when the hight is less than the (**height** / 2) gonna get some negative values, that's why we gonna work only with the little **h**, but with that we will map the actual real **HEIGHT** of the image between -1 and 1, so that **HEIGHT** / 2 gonna get us a solid **0**.

But keep in mind that the little **h** has nothing to do with the real **HEIGHT** of the image, it's related to the **FOV** if you still remember.

So far it's been a lot of talking, we didn't even start yet. **LET'S BEGAIN THE SHOW.**

So

		h = tang(FOV / 2)

		which means that :

		w = h * ar 

		because :
		
		ar = WIDTH / HEIGHT = w / h

This guy will explane every thing about these formulas:

https://www.youtube.com/watch?v=LRN_ewuN_k4&t=203s

Now we have **h** and **w**, but how we gonna use them to generate rays. To do so, we still need tow vectors the up and the right vectors. Let's se how to get them first.

#### Up and Right Vectors

If you already watched that vedio, you will notice that in his case, he didn't need to worry about calculating the up vector cause he had it already in the camera's discreption, but in our case we don't have that piece of information, which means that we need to calculate it ourselves.

And about the right vector, that one is easy to get once we have the up, will lead us the right vector.

##### Up

We need to relay on an existed piece of information, which is the forward vector, that the camera provided us with.

Let's first talk about something called the cross product, when we have two vectors, the cross product of these two will give you another vector which is perpendicular on both of them.

Take a look at this :

https://www.mathsisfun.com/algebra/vectors-cross-product.html

So we need to choose one of the vetors that we already have in our space, which are *i* the vector that holds the x-axis, *j* the one that holds the y-axis and *k* that's going with the z-axis.

Take one of them, calculate the cross product between that last one and the forward direction of the camera, and that will give you the up vector of your camera.

It's up to you which one to choose.

There can be a small problem if we used this approach, the problem occurred when u give the forward direction of the camera the same as the vector you have choosed to calculate the up vector with. The cross product of a vector with itself gives a null vector (0,0,0), and that's not a valide vector to work with. How to solve this little problem ? just by adding a small value to one of the forward vector compoinents, and by that you gonna avoid having the same vector.

The value can be something like : 0.000001

**It won't effect.**

##### Right

I guess this one is easy to get, we will use the cross product again, and cause we already have the up vector we will ``cross it (i don't know if i can say it this way)`` with the forward vector to get the right vector.

See it's not that hard to get the right thing, **always easy**.

Now we have every thing setup to calculate the ray direction. We still need one step and we will be just fine, and ready to rock.

#### Direction

To calculate the direction of every ray, we just need to mix up all the above factors in one `singl` formula **(it's alright to be singl)**.

I gusse you already know the formula from that vedio, and if you didn't watch it yet here's the link again:

https://www.youtube.com/watch?v=LRN_ewuN_k4&t=203s

		(up * h * y) + (right * w * x) + forword

This is the formula, just plug your x and y in it and you will get the direction of that next ray. That easy.

But x and y are the coordinates of which pixel we are in at that time. which means that x and y are mapped between 0 and **HEIGHT** for y and between 0 and **WIDTH** for x. But for them to work in our formula they need to be between -1 and 1.

**MAP THEM BEFORE THAT**

I think now our camera is working fine, and it can shoot rays trough each pixel. And that's the only thing it was meant to do.

## Itersections

After we shoot rays though every pixel, we need to calculate whether we've got intersected with an object or not, to do this each one of these objects has his own formula, this last one is represented with x , y and z. So we gonna pluge the parametrique equation in every singl one of them, by doing that we gonna get only one variable is the **t** the parameter. We solve the equation and we find out whether it's possible to find a valid value for **t**. 

That's all i've got to say about **intersections**, but here are some links that i found useful.

https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm

https://www.youtube.com/watch?v=4NshnkzOdI0&t=1648s

https://www.youtube.com/watch?v=v9vndyfk2U8

## Light

What's going to happen if we hit an object?. Simply we gonna color that last pixel with the color of that object, makes sence right?. But that a prroach will give us a flat color, and you can't make 3D images like that.

What makes 3D looks like 3D, is the shading i guess, and we can't talk about shading without inclouding the light source. So after we hit a point in the object we need to see whether that point in shade or lighted.

To do so, we gonna need to send another ray from the intersection point to the source of light, and if we hit something in our way, that means that the pixel we are at is shaded, other ways it's lighted. As easy as that.

They say that the objects aren't totaly in the dark, that means is even if the point is shaded, that pixel won't be black, so we gonna need to add the ambient light to the object's color.

### Ambient

The ambient light is the light that is around the space, so we need to add it to to every pixel, whether that last one is in the dark or lighted.

How we gonna do it?, it's quite simple, we need to map the ambient color values from [0, 255] to [0, 1], after that we gonna multiplay these values by the ambient ratio. As simple as that.

Multiplaying two colors means to multiplay the red component by the red component, the green by the green and the blue by the blue, and the result will always be between 0 and 255.

To map a value from from [0, 255] to [0, 1], you gonna need to devided that value by 255, the result will be btween 0 and 1.

If that point is lighted, we need to see how is the light effecting it, in other words, is it facing toward the light or facing a way from it. There's something called the normal vector on that point, what's we gonna do with it, we need to masur the angle between the light vector and the normal vector on that point, and as big as that angel gets the less light is getting to that point, and vice versa. That's what we call the diffuse.

### Diffuse

How to calculate the diffuse is easy, but we need first to get the normal on that point, and each shape has it's own ways to calculate the normal, shapes are not the same.

After we get that done, we need the light vector, and that is quite easy to get we just need to subtract the point where our light is at from the point of intersection. That gives us a vector. 

**EACH VECTOR OF THESE NEED TO BE NORMALIZED**

Now we just gonna calculate the dot produt of these last two vectors. The dot product basically is the cos of the angel between two vectors, and the cos is a value between -1 and 1, that is why we need our vectors normalized so that the result of the dot product never leavs that range.

That dot product value is the diffuse, now we need to applay it of the color of that pixel. First of all we need to have the light color mapped to the range **[0,1]**, after that we gonna multiplay that color by the light ratio and the diffuse. That will give us the diffuse part, which means that our color is not done yet.

Here is a linke that can help :

https://www.youtube.com/watch?v=FiYDkMZCSF4&list=PLlrATfBNZ98edc5GshdBtREv5asFW3yXl&index=5

### Specular

This last color component, calculates the shininess of that point in the object, and that last one is related to the shininess nature of every object, and to another factor which is the angle between view vector and the reflation vector. We need to calculate the reflation vector first, that is some pure math, that's why im gonna leave some links that will help you get a deeper understanding about the whole thing.

The view vector is the vector that is going from the point of intersection towards the camera, and i think that is easy to get, we only need to inverse the ray direction, cause the ray is coming from the camera, isn't ?.

Here is some links that will get you going :

https://www.scratchapixel.com/lessons/3d-basic-rendering/phong-shader-BRDF/phong-illumination-models-brdf

https://www.robots.ox.ac.uk/~att/index.html

https://www.youtube.com/watch?v=KdDdljGtfeg

https://www.youtube.com/watch?v=KdDdljGtfeg&t=305s

https://www.geeksforgeeks.org/phong-model-specular-reflection-in-computer-graphics/

After we get these 3 components we need to add them to each other, and after we get that we need to multiplay the result by the color of the object and that is the color of that pixel.

		final color = (ambient + diffuse + specular)  * the object color

We just implemented the **PHONG REFLECTION MODEL**.

https://en.wikipedia.org/wiki/Phong_reflection_model

As you might already notice that this algorithm is slow, very slow cause it takes a lot of computation, but it gives a decent results, the only problem about it is that it's expensive.

How can we make it do better ?. We can use multi-threading, instead of doing the whole image at once we can devide it to multiple threads, and that will make our program run a little faster.

We can also increase the resolution, to get sharp images. We just need to shoot 4 or 16 ray through out each pixel and average that colors into one and that's the color for that pixel. You can shoot more then that, the higher the number the better the resolution you get. And this approach called the anti-aliasing.

You can do a lot of thing, to get realistic images, like refraction and reflection. We gonna keep that to another version.

