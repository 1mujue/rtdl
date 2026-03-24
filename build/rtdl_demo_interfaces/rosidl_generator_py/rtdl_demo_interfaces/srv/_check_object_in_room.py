# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rtdl_demo_interfaces:srv/CheckObjectInRoom.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CheckObjectInRoom_Request(type):
    """Metaclass of message 'CheckObjectInRoom_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rtdl_demo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rtdl_demo_interfaces.srv.CheckObjectInRoom_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__check_object_in_room__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__check_object_in_room__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__check_object_in_room__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__check_object_in_room__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__check_object_in_room__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CheckObjectInRoom_Request(metaclass=Metaclass_CheckObjectInRoom_Request):
    """Message class 'CheckObjectInRoom_Request'."""

    __slots__ = [
        '_object_name',
        '_room_name',
    ]

    _fields_and_field_types = {
        'object_name': 'string',
        'room_name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.object_name = kwargs.get('object_name', str())
        self.room_name = kwargs.get('room_name', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.object_name != other.object_name:
            return False
        if self.room_name != other.room_name:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def object_name(self):
        """Message field 'object_name'."""
        return self._object_name

    @object_name.setter
    def object_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'object_name' field must be of type 'str'"
        self._object_name = value

    @builtins.property
    def room_name(self):
        """Message field 'room_name'."""
        return self._room_name

    @room_name.setter
    def room_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'room_name' field must be of type 'str'"
        self._room_name = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_CheckObjectInRoom_Response(type):
    """Metaclass of message 'CheckObjectInRoom_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rtdl_demo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rtdl_demo_interfaces.srv.CheckObjectInRoom_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__check_object_in_room__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__check_object_in_room__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__check_object_in_room__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__check_object_in_room__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__check_object_in_room__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CheckObjectInRoom_Response(metaclass=Metaclass_CheckObjectInRoom_Response):
    """Message class 'CheckObjectInRoom_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_found',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'found': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        self.found = kwargs.get('found', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.found != other.found:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def found(self):
        """Message field 'found'."""
        return self._found

    @found.setter
    def found(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'found' field must be of type 'bool'"
        self._found = value


class Metaclass_CheckObjectInRoom(type):
    """Metaclass of service 'CheckObjectInRoom'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rtdl_demo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rtdl_demo_interfaces.srv.CheckObjectInRoom')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__check_object_in_room

            from rtdl_demo_interfaces.srv import _check_object_in_room
            if _check_object_in_room.Metaclass_CheckObjectInRoom_Request._TYPE_SUPPORT is None:
                _check_object_in_room.Metaclass_CheckObjectInRoom_Request.__import_type_support__()
            if _check_object_in_room.Metaclass_CheckObjectInRoom_Response._TYPE_SUPPORT is None:
                _check_object_in_room.Metaclass_CheckObjectInRoom_Response.__import_type_support__()


class CheckObjectInRoom(metaclass=Metaclass_CheckObjectInRoom):
    from rtdl_demo_interfaces.srv._check_object_in_room import CheckObjectInRoom_Request as Request
    from rtdl_demo_interfaces.srv._check_object_in_room import CheckObjectInRoom_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
